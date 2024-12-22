#include<stdio.h>
#include<string.h>
struct sinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
int main() {
    struct sinhVien sv[50] = {
        {1, "Dinh Quang Huy", 18, "0879245112"},
        {2, "Dinh Huy Quang", 18, "0726849618"},
        {3, "Quang Huy Dinh", 18, "08254826875"},
        {4, "Huy Quang Dinh", 18, "0999999999"},
        {5, "Quang Dinh Huy", 18, "09875298787"}
    };
    int n = 5;
    printf("Nhap thong tin sinh vien moi:\n");
    sv[n].id = n + 1;
    printf("Nhap ten: ");
    fflush(stdin);
    fgets(sv[n].name, sizeof(sv[n].name), stdin);
    printf("Nhap tuoi: ");
    scanf("%d",&sv[n].age);
    printf("Nhap so dien thoai: ");
    scanf("%s", sv[n].phoneNumber);
    n++;
    printf("\nThong tin tat ca sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n\n", sv[i].phoneNumber);
    }
    return 0;
}

