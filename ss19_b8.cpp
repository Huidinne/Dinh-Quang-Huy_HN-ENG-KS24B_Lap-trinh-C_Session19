#include <stdio.h>
#include <string.h>
struct sinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void hienThiDanhSach(struct sinhVien sv[], int n);
void insertSv(struct sinhVien sv[], int *n, int index, struct sinhVien newSv);
int main() {
    struct sinhVien sv[50] = {
        {1, "Dinh Quang Huy", 18, "0879245112"},
        {2, "Dinh Huy Quang", 18, "0726849618"},
        {3, "Quang Huy Dinh", 18, "08254826875"},
        {4, "Huy Quang Dinh", 18, "0999999999"},
        {5, "Quang Dinh Huy", 18, "09875298787"}
    };
    int n = 5;

    printf("Danh sach sinh vien ban dau:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n\n", sv[i].phoneNumber);
    }

    struct sinhVien newSv;
    int index;
    printf("\nNhap vi tri can chen: ");
    scanf("%d", &index);
    fflush(stdin);

    printf("Nhap ID sinh vien: ");
    scanf("%d", &newSv.id);
    fflush(stdin);

    printf("Nhap ten sinh vien: ");
    fgets(newSv.name, sizeof(newSv.name), stdin);
    newSv.name[strcspn(newSv.name, "\n")] = '\0';

    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &newSv.age);
    fflush(stdin);

    printf("Nhap so dien thoai sinh vien: ");
    fgets(newSv.phoneNumber, sizeof(newSv.phoneNumber), stdin);
    newSv.phoneNumber[strcspn(newSv.phoneNumber, "\n")] = '\0';

    insertSv(sv, &n, index, newSv);

    printf("\nDanh sach sinh vien sau khi chen:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n\n", sv[i].phoneNumber);
    }
    return 0;
}
void insertSv(struct sinhVien sv[], int *n, int index, struct sinhVien newSv) {
    if (index < 0 || index > *n) {
        printf("Vi tri khong hop le\n");
        return 0;
    }
    for (int i = *n; i > index; i--) {
        sv[i] = sv[i - 1];
    }
    sv[index] = newSv;
    (*n)++;
}

