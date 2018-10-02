#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[50];
    char name[50];
    char phone[50];

} Student;
Student listStudent[50];

int count = 0;

int createStudent() {
    int size;
    printf("Nhap so luong nhan vien ban can dien:\n");
    scanf("%d", &size);
    Student myStudent[size];
    for (int i = 0; i < size; ++i) {
        printf("Nhap ma cua ban:\n");
        fgets(myStudent[i].id, 50, stdin);
        if (!myStudent[i].id, '\n') {
            while (fgetc(stdin) != '\n');
        }
        printf("Nhap ten cua ban: \n");
        fgets(myStudent[i].name, 50, stdin);
        if (!myStudent[i].name, '\n') {
            while (fgetc(stdin) != '\n');
        }
        printf("nhap so dien thoai cua ban: \n");
        fgets(myStudent[i].phone, 50, stdin);
        if (!myStudent[i].phone, '\n') {
            while (fgetc(stdin) != '\n');
        }
        count++;
    }
    return count;
}

void displayStudent() {
    printf("%-10s%-20s%-10s%-20s%-10s%-20s", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Ði?n tho?i");
    for (int i = 0; i < count; ++i) {
        printf("%-10s%-20s%-10s%-20s%-10s%-20s\n", "", listStudent[i].id, "|", listStudent[i].name, "|",
               listStudent[i].phone);
    }
}

void readFile() {
    FILE *fp;
    fp = fopen("danhsachsinhvien.txt", "r");
    char buff[500];
    while (fgets(buff, 50, fp) != NULL) {
        printf("%s", buff);
    }
}

void writeFile() {
    FILE *fp;
    fp = fopen("danhsachsinhvien.txt", "w+");
    fprintf(fp, "%-10s%-20s%-10s%-20s%-10s%-20s", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Ði?n tho?i");
    for (int i = 0; i < count; ++i) {
        fprintf(fp, "%-10s%-20s%-10s%-20s%-10s%-20s\n", "", listStudent[i].id, "|", listStudent[i].name, "|",
                listStudent[i].phone);
    }
    fclose(fp);

}


int main() {


    int choice;
    while (1 == 1) {
        printf("\n---------Quan ly sinh vien---------\n");
        printf("1.Them moi sinh vien\n");
        printf("2.Hien Thi sinh vien\n");
        printf("3.Luu danh sach sinh vien ra file\n");
        printf("4.Doc danh sach sinh vien tu file\n");
        printf("5.Thoat chuong trinh\n");
        printf("Moi ban nhap lua chon (1,2,3,4,5):\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("1.Them moi sinh vien\n");
                createStudent();
                break;
            case 2:
                printf("2.Hien Thi sinh vien\n");
                displayStudent();
                break;
            case 3:
                printf("3.Luu danh sach sinh vien ra file\n");
                writeFile();
                break;
            case 4:
                printf("4.Doc danh sach sinh vien tu file\n");
                readFile();
                break;
            case 5:
                printf("ket thuc!");
                exit(1);
            default:
                break;
        }
    }

}
