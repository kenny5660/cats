#include <sstream>
#include <string>
#include <vector>

class FormatVisitor : public BaseVisitor {
 public:
  void Visit(const BaseNode* node) override { node->Visit(this); }

  void Visit(const ClassDeclarationNode* node) override {
    std::string offset = stream_.str();
    stream_ << "class " << node->ClassName() << " {";
    end_line();

    auto pub_fiealds = node->PublicFields();
    if (pub_fiealds.size() > 0) {
      stream_ << offset << "  public:";
      end_line();
      for (int i = 0; i < pub_fiealds.size(); ++i) {
        stream_ << "    " << offset;
        Visit(pub_fiealds[i]);
        stream_ << ";";
        end_line();
      }
    }

    auto prot_fiealds = node->ProtectedFields();
    if (prot_fiealds.size() > 0) {
      end_line();
      stream_ << offset << "  protected:";
      end_line();
      for (int i = 0; i < prot_fiealds.size(); ++i) {
        stream_ << "    " << offset;
        Visit(prot_fiealds[i]);
        stream_ << ";";
        end_line();
      }
    }

    auto priv_fiealds = node->PrivateFields();
    if (priv_fiealds.size() > 0) {
      end_line();
      stream_ << offset << "  private:";
      end_line();
      for (int i = 0; i < priv_fiealds.size(); ++i) {
        stream_ << "    " << offset;
        Visit(priv_fiealds[i]);
        stream_ << ";";
        end_line();
      }
    }
    stream_ << offset << "}";
  }
  void Visit(const VarDeclarationNode* node) override {
    stream_ << node->TypeName() << " " << node->VarName();
  }
  void Visit(const MethodDeclarationNode* node) override {
    stream_ << node->ReturnTypeName() << " " << node->MethodName() << "(";
    auto args = node->Arguments();
    if (args.size() > 0) {
      for (int i = 0; i < args.size() - 1; ++i) {
        Visit(args[i]);
        stream_ << ", ";
      }
      Visit(args[args.size() - 1]);
    }
    stream_ << ")";
  }

  const std::vector<std::string>& GetFormattedCode() {
    stream_ << ";";
    formated.push_back(stream_.str());
    return formated;
  }

 private:
  void end_line() {
    formated.push_back(stream_.str());
    stream_.str("");
  }
  std::vector<std::string> formated;
  std::stringstream stream_;
};
