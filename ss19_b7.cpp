#include <stdio.h>
#include <string.h>

struct sinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void deleteSv(struct sinhVien sv[], int *n, char deleteName[]);
int main() {
    struct sinhVien sv[50] = {
        {1, "Dinh Quang Huy", 18, "0879245112"},
        {2, "Dinh Huy Quang", 18, "0726849618"},
        {3, "Quang Huy Dinh", 18, "08254826875"},
        {4, "Huy Quang Dinh", 18, "0999999999"},
        {5, "Quang Dinh Huy", 18, "09875298787"}
    };
    int n = 5;
    char deleteName[50];
    printf("Nhap ten sinh vien can xoa: ");
    fflush(stdin);
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';
    deleteSv(sv, &n, deleteName);
    printf("Danh sach sinh vien hien tai:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n\n", sv[i].phoneNumber);
    }
    return 0;
}
void deleteSv(struct sinhVien sv[], int *n, char deleteName[]) {
    int flag = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp(sv[i].name, deleteName) == 0) {
            flag = 1;
            for (int j = i; j < *n - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*n)--;
            printf("Da xoa sinh vien\n");
            return;
        }
    }
    if (flag==-1) {
        printf("Khong tim thay\n");
    }
}

