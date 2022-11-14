#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define ALL_PRODUCT 5

double discount_price(double price, int discount) {
	return price - (price * discount) / 100;
	}

int main(void) {
	int code[ALL_PRODUCT] = { 1000, 1001, 1102, 1023, 1149 };
	char product[ALL_PRODUCT][40] = {
		"тетрадь 48 л.",
		"тетрадь 96 л.",
		"шарикова€ ручка",
		"маркер",
		"циркуль"
	};
	double price[ALL_PRODUCT] = { 65, 108, 25, 56, 250 };
	int num=0, discount[ALL_PRODUCT] = {15, 20, 0, 10, 30};
	double sum = 0;
	char str[5] = "    ";
	int buff[50], num_buff = 0;

	setlocale(LC_ALL, "Russian");

	for (int i = 0; i < ALL_PRODUCT; i++) {
		printf("код: %d, наименование: ", code[i]);
		fputs(product[i], stdout);
		printf("\n");
	}
	while (strcmp(str, "quit") && strcmp(str, "exit")) {
		printf("¬ведите код товара или quit(exit) дл€ выхода: ");
		scanf_s("%s", str, 5);
		if (strspn(str, "0123456789")) {
			num = atoi(str);
			for (int i = 0; i < ALL_PRODUCT; i++) 
				if (code[i] == num) {
					buff[num_buff] = code[i];
					num_buff++;
					printf("“овар в чеке: %d, %d\n", code[i], num_buff);
					//					fputs(product[i], stdout);
					//					printf("\tprice - %0.2f,\t discount - %d%%, discount price - %0.2f\n", price[i], discount[i], discount_price(price[i], discount[i]));
				}
		}
	}
	for (int i = 0; i < num_buff; i++)
		for (int j = 0; j < ALL_PRODUCT; j++) {
			if (code[j] == buff[i]) {
					fputs(product[j], stdout);
					printf("\tprice - %0.2f,\t discount - %d%%, discount price - %0.2f\n", price[j], discount[j], discount_price(price[j], discount[j]));
					sum += discount_price(price[j], discount[j]);
			}
		}

	printf("сумма - %0.2f", sum);
}