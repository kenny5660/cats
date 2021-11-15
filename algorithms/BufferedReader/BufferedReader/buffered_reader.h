#include <vector>

class BufferedReader {
 public:
  explicit BufferedReader(PackageStream* stream);
  int32_t Read(char* buf, int32_t bytes);

 private:
  PackageStream* stream_;
  std::vector<char> buffer_;
};

BufferedReader::BufferedReader(PackageStream* stream) : stream_(stream) {}

int32_t BufferedReader::Read(char* buf, int32_t bytes) {
  for (int i = 0; i < buffer_.size(); ++i) {
    if (i == bytes) {
      buffer_.erase(buffer_.begin(), buffer_.begin() + bytes);
      return bytes;
    }
    buf[i] = buffer_[i];
  }
  int real_bytes = buffer_.size();
  char* after_buf = &(buf[buffer_.size()]);
  int i = 0;
  for (i = 0; i < (bytes - real_bytes) / stream_->PackageLen(); ++i) {
    int stream_real_bytes = stream_->ReadPackage(after_buf);
    if (stream_real_bytes < stream_->PackageLen()) {
      return i * stream_->PackageLen() + stream_real_bytes + real_bytes;
    }
    after_buf = &(after_buf[stream_real_bytes]);
  }
  real_bytes += i * stream_->PackageLen();
  buffer_.clear();
  if (real_bytes == bytes) {
    return real_bytes;
  }
  buffer_.resize(stream_->PackageLen());
  int stream_real_bytes = stream_->ReadPackage(buffer_.data());

  for (i = 0; i < bytes - real_bytes; ++i) {
    if (i == stream_real_bytes) {
      buffer_.clear();
      return real_bytes + stream_real_bytes;
    }
    buf[real_bytes + i] = buffer_[i];
  }
  buffer_.erase(buffer_.begin(), buffer_.begin() + bytes - real_bytes);
  return bytes;
}
