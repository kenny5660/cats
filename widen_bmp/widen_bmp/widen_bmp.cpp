// widen_bmp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>

typedef struct {
	char signature[3];
	uint32_t file_size, file_size_real, bfOffBits, BITMAPINFO_size, compression, size_img, biClrUsed, biClrImportant;
	long img_Width, img_Height, img_width_bytes_mul4, biXPelsPerMeter, biYPelsPerMeter;
	uint16_t biPlanes, biBitCount;
	uint8_t** img_data;
}BMP;

int bmp_read(BMP *bmp, const char* filename);
int bmp_write(BMP *bmp, const char* filename);
int multiple_4(int number);
BMP bmp_widen(BMP *bmp);

int main(int argc, char* argv[])
{
	if (argc < 2) {
		fprintf(stderr, "wrong args");
		printf("wrong args");
		return -1;
	}

	BMP bmp,newbmp;
	bmp_read(&bmp, argv[1]);
	//bmp_write(&(bmp_widen(&bmp)),argv[2]);
	bmp_write(&bmp, argv[2]);
	return 0;
}

int multiple_4(int number) {
	int tmp;
	if ((tmp = number % 4) != 0) {
		number += number > -1 ? (4 - tmp) : tmp;
	}
	return number;
}
BMP bmp_widen(BMP *bmp) {
	BMP newbmp;
	newbmp = *bmp;

	newbmp.img_data = (uint8_t**)malloc(newbmp.img_Height * sizeof(uint8_t*));
	for (long i = 0; i < newbmp.img_Height; i++) {
		newbmp.img_data[i] = (uint8_t*)malloc(newbmp.img_width_bytes_mul4 * sizeof(uint8_t));
		long newj = 0;
		for (long j = bmp->img_Width / 4; j < bmp->img_Width / 4 + bmp->img_Width / 2; j++) {
			newbmp.img_data[i][newj*(newbmp.biBitCount / 8)] = bmp->img_data[i][j*(newbmp.biBitCount / 8)];
			newbmp.img_data[i][newj*(newbmp.biBitCount / 8)+1] = bmp->img_data[i][j*(newbmp.biBitCount / 8)+1];
			newbmp.img_data[i][newj*(newbmp.biBitCount / 8)+2] = bmp->img_data[i][j*(newbmp.biBitCount / 8)+2];
			newj++;
			newbmp.img_data[i][newj*(newbmp.biBitCount / 8)] = bmp->img_data[i][j*(newbmp.biBitCount / 8)];
			newbmp.img_data[i][newj*(newbmp.biBitCount / 8) + 1] = bmp->img_data[i][j*(newbmp.biBitCount / 8) + 1];
			newbmp.img_data[i][newj*(newbmp.biBitCount / 8) + 2] = bmp->img_data[i][j*(newbmp.biBitCount / 8) + 2];
			newj++;
		}

	}
	return newbmp;
}
int bmp_write(BMP *bmp, const char* filename) {
	FILE* fout_bmp = fopen(filename, "wb");
	if (fout_bmp == NULL) {
		fprintf(stderr, "Can't open file");
		printf("Can't open file");
		return -1;
	}
	fwrite("BM", 1, 2, fout_bmp);
	fwrite(&(bmp->file_size), sizeof(uint32_t), 1, fout_bmp);
	fwrite("\0\0\0\0", sizeof(char), 4, fout_bmp);
	fwrite(&(bmp->bfOffBits), sizeof(uint32_t), 1, fout_bmp);
	fwrite(&(bmp->BITMAPINFO_size), sizeof(uint32_t), 1, fout_bmp);
	fwrite(&(bmp->img_Width), sizeof(long), 1, fout_bmp);
	fwrite(&(bmp->img_Height), sizeof(long), 1, fout_bmp);
	fwrite(&(bmp->biPlanes), sizeof(uint16_t), 1, fout_bmp);
	fwrite(&(bmp->biBitCount), sizeof(uint16_t), 1, fout_bmp);
	fwrite(&(bmp->compression), sizeof(uint32_t), 1, fout_bmp);
	fwrite(&(bmp->size_img), sizeof(uint32_t), 1, fout_bmp);
	fwrite(&(bmp->biXPelsPerMeter), sizeof(long), 1, fout_bmp);
	fwrite(&(bmp->biYPelsPerMeter), sizeof(long), 1, fout_bmp);
	fwrite(&(bmp->biClrUsed), sizeof(uint32_t), 1, fout_bmp);
	fwrite(&(bmp->biClrImportant), sizeof(uint32_t), 1, fout_bmp);

	setvbuf(fout_bmp, NULL, _IOFBF, bmp->size_img / 8);
	fseek(fout_bmp, bmp->bfOffBits, SEEK_SET); //to iamge data

	for (long i = bmp->img_Height - 1; i >= 0; --i) {
		fwrite(bmp->img_data[i], sizeof(uint8_t), bmp->img_width_bytes_mul4, fout_bmp);
	}
	fclose(fout_bmp);
}
int bmp_read(BMP *bmp, const char* filename) {
	FILE* finput_bmp = fopen(filename, "rb");
	if (finput_bmp == NULL) {
		fprintf(stderr, "Can't open file");
		printf("Can't open file");
		return -1;
	}
	fread(bmp->signature, 1, 2, finput_bmp);
	bmp->signature[2] = '\0';
	if (strcmp(bmp->signature, "BM") != 0) {
		fprintf(stderr, "Error signature");
		printf("Error signature");
		return -1;
	}
	fread(&(bmp->file_size), sizeof(uint32_t), 1, finput_bmp);
	int fptr_cur = ftell(finput_bmp);
	fseek(finput_bmp, 0, SEEK_END);
	bmp->file_size_real = ftell(finput_bmp);
	if (bmp->file_size != bmp->file_size_real) {
		fprintf(stderr, "File corrupted, wrong file size");
		printf("File corrupted,wrong file size");
		return -1;
	}
	fseek(finput_bmp, fptr_cur + 4, SEEK_SET);//pointer to 	bfOffBits
	fread(&(bmp->bfOffBits), sizeof(uint32_t), 1, finput_bmp);
	fread(&(bmp->BITMAPINFO_size), sizeof(uint32_t), 1, finput_bmp);
	fread(&(bmp->img_Width), sizeof(long), 1, finput_bmp);
	fread(&(bmp->img_Height), sizeof(long), 1, finput_bmp);
	fread(&(bmp->biPlanes), sizeof(uint16_t), 1, finput_bmp);
	fread(&(bmp->biBitCount), sizeof(uint16_t), 1, finput_bmp);
	fread(&(bmp->compression), sizeof(uint32_t), 1, finput_bmp);
	fread(&(bmp->size_img), sizeof(uint32_t), 1, finput_bmp);
	fread(&(bmp->biXPelsPerMeter), sizeof(long), 1, finput_bmp);
	fread(&(bmp->biYPelsPerMeter), sizeof(long), 1, finput_bmp);
	fread(&(bmp->biClrUsed), sizeof(uint32_t), 1, finput_bmp);
	fread(&(bmp->biClrImportant), sizeof(uint32_t), 1, finput_bmp);

	if (bmp->compression != 0) {
		fprintf(stderr, "File compression unsupported");
		printf("File compression unsupported");
		return -2;
	}
	if (bmp->size_img == 0) {
		bmp->size_img = bmp->img_Width*bmp->img_Height*(bmp->biBitCount / 8);
	}
	setvbuf(finput_bmp, NULL, _IOFBF, bmp->size_img / 8);
	fseek(finput_bmp, bmp->bfOffBits, SEEK_SET); //to iamge data;fout_bmp
	bmp->img_width_bytes_mul4 = multiple_4(bmp->img_Width*bmp->biBitCount / 8);
	bmp->img_data = (uint8_t**)malloc(bmp->img_Height * sizeof(uint8_t*));
	if (bmp->img_Height > 0) {
		for (long i = bmp->img_Height - 1; i >= 0; --i) {
			bmp->img_data[i] = (uint8_t*)malloc(bmp->img_width_bytes_mul4 * sizeof(uint8_t));
			fread(bmp->img_data[i], sizeof(uint8_t), bmp->img_width_bytes_mul4, finput_bmp);

		}
	}

	fclose(finput_bmp);
}