#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// To‘g‘ri butun sonni kiritish funksiyasi
int get_int_input(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) break;
        else {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); 
        }
    }
    return value;
}

// To‘g‘ri matnni kiritish funksiyasi
void get_string_input(const char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    scanf("%s", buffer);
    buffer[size - 1] = '\0'; 
}

// Foydalanuvchini ro'yxatdan o'tkazish funksiyasi
void register_user() {
    char ism[14], familiya[20], otasining_ismi[20], elektron_pochta[30];
    int yosh, parol, parol_takror, telefon_raqami;

    while (1) {
        get_string_input("Ismingizni kiriting: ", ism, sizeof(ism));
        get_string_input("Familiyangizni kiriting: ", familiya, sizeof(familiya));
        get_string_input("Otangizning ismini kiriting: ", otasining_ismi, sizeof(otasining_ismi));

        yosh = get_int_input("Yoshingizni kiriting: ");
        if (yosh < 20) {
            printf("Siz 20 yoshdan kichiksiz. Sizda imkoniyatlar soni cheklangan bo'ladi!\n");
        }

        get_string_input("Elektron pochtangizni kiriting: ", elektron_pochta, sizeof(elektron_pochta));

        parol = get_int_input("Parolingizni kiriting: ");
        while (1) {
            parol_takror = get_int_input("Parolingizni takrorlang: ");
            if (parol_takror == parol) break;
            else printf("Parol xato! Qayta urinib kuring!\n");
        }

        telefon_raqami = get_int_input("Telefon raqamingizni kiriting: ");

        printf("Qabul qilindi. Sizning ma'lumotlaringiz. Tekshirishingiz mumkin:\n");
        printf("Ism: %s\nFamiliya: %s\nOtasining ismi: %s\nYosh: %d\nElektron pochta: %s\nTelefon raqami: %d\n",
               ism, familiya, otasining_ismi, yosh, elektron_pochta, telefon_raqami);

        int verification = get_int_input("Agar ma'lumot to'g'ri bo'lsa 1, aks holda 0 belgisi qoldirilsin: ");
        if (verification == 1) break;
        else printf("Ma'lumotlarni qayta kiritishingizni so'raymiz.\n");
    }

    // Muvaffaqiyatli ro'yxatdan o'tish
    printf("Tabriklaymiz! Siz registratsiyadan muavfaqiyatli o'tdingiz!\n");
    printf("Hurmatli %s %s %s! Siz muvafaqiyatli ro'yxatdan o'tdingiz!\n", ism, familiya, otasining_ismi);
    printf("fro.com/%s\n", elektron_pochta);
    printf("Bu kodni hech kimga bermang: 26739\n");
    printf("Xurmatli mijoz, ma'lumotlaringiz saqlandi.\n");

    // Yakuniy qism
    int completion = get_int_input("Siz to'laqonli ro'yxatdan o'tish jarayonini tugatmoqchimisiz? (HA bo'lsa 1 ni tanlang, aks holda 0 ni): ");
    if (completion == 1) {
        printf("Jarayon tugadi. Etiboringiz uchun raxmat!\n");
    } else {
        printf("Davom ettirish uchun linkngizdan foydalangan holda keyingi oynaga o'tshingiz mumkin.\n");
        printf("Ro'yxatdan o'tish yakunlandi.\n");
    }
}

int main() {
    printf("\tAssalomaleykum! Xush kelibsiz!\n");
    printf("Registratsiyani boshlash uchun quyidagi ma'lumotlarni kiriting:\n");

    register_user();

    return 0;
}
