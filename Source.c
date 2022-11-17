#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define ALL_PRODUCT 5

double discount_price(double price, int discount) {
	return price - (price * discount) / 100;
	}

int main(void) {
	struct prod {
		int code;
		double price;
		int discount;
		char product[40];
	} p[ALL_PRODUCT] = { 1000, 65, 15, "notepade 48 p.",
						 1001, 108, 20, "notepade 96 p.",
						 1102, 25, 0, "pen",
						 1023, 56, 10, "marker",
						 1149, 250, 30, "drawing compass"
						};

	/*	for (int i = 0; i < ALL_PRODUCT; i++) {
		printf("code - %d,\tprice - %0.2f,\tdiscount - %d%%,\tdiscount price - %0.2f,\t", p[i].code, p[i].price, p[i].discount, discount_price(p[i].price, p[i].discount));
		fputs(p[i].product, stdout);
		printf("\n");
	}*/

	double sum = 0;
	char str[5] = "    ";
	int buff[50], num_buff = 0, num = 0;

	setlocale(LC_ALL, "Russian");

	for (int i = 0; i < ALL_PRODUCT; i++) {
		printf("код: %d, наименование: ", p[i].code);
		fputs(p[i].product, stdout);
		printf("\n");
	}
	while (strcmp(str, "quit") && strcmp(str, "exit")) {
		printf("Введите код товара или quit(exit) для выхода: ");
		scanf_s("%s", str, 5);
		if (strspn(str, "0123456789")) {
			num = atoi(str);
			for (int i = 0; i < ALL_PRODUCT; i++) 
				if (p[i].code == num) {
					buff[num_buff] = p[i].code;
					num_buff++;
					printf("Товар в чеке: %d, %d\n", p[i].code, num_buff);
				}
		}
	}
	for (int i = 0; i < num_buff; i++)
		for (int j = 0; j < ALL_PRODUCT; j++) {
			if (p[j].code == buff[i]) {
					printf("price - %0.2f,\tdiscount - %d%%,\tdiscount price - %0.2f\t", p[j].price, p[j].discount, discount_price(p[j].price, p[j].discount));
					fputs(p[j].product, stdout);
					printf("\n");
					sum += discount_price(p[j].price, p[j].discount);
			}
		}

	printf("сумма - %0.2f", sum);
	return 0;
}