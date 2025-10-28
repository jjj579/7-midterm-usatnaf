// hansan.c (�ѻ� ����)
#include <stdio.h>

#define CMD_RELOAD		0x01 // Bit 0 - ���� �غ�	0000 0001
#define CMD_FIRE		0x02 // Bit 1 - ���� ���	0000 0010
#define CMD_CHARGE		0x04 // Bit 2 - ���� ����	0000 0100
#define CMD_HOLD		0x08 // Bit 3 - ���� �غ�	0000 1000
#define CMD_CRANE_FORM	0x10 // Bit 4 - ������ ����	0001 0000
#define CMD_EVAC		0x20 // Bit 5 - �λ� �ļ�	0010 0000
#define CMD_DAMAGE		0x40 // Bit 6 - ���� ���	0100 0000

// Toggle ��� ON
unsigned char CommandOn(unsigned char fleet, unsigned char bit) {
	if (bit < 7)
		fleet |= (0x01 << bit);
	return fleet;
}

// Toggle ��� OFF
unsigned char CommandOff(unsigned char fleet, unsigned char bit) {
	if (bit < 7)
		fleet &= ~(0x01 << bit);
	return fleet;
}

// ���� ǥ��
void showStatus(unsigned char fleet) {
	printf("\n[���� �Լ� ����] HEX: %02X | BIN: ", fleet);
	for (int i = 7; i >= 0; i--) {
		printf("%d", (fleet >> i) & 1);
	}
	printf("\n");

	if (fleet & CMD_RELOAD)		printf("���� �غ� �Ϸ�\n");
	if (fleet & CMD_FIRE)		printf("���� ��� Ȱ��\n");
	if (fleet & CMD_CHARGE)		printf("���� ���� ����\n");
	if (fleet & CMD_HOLD)		printf("���� �غ� ��\n");
	if (fleet & CMD_CRANE_FORM)	printf("������ ���� ����\n");
	if (fleet & CMD_EVAC)		printf("�λ� �ļ�\n");
	if (fleet & CMD_DAMAGE)		printf("�Լ� ���� �߻�!\n");
	if (fleet == 0)				printf("��� �Լ� ��� ����\n");
}

void printMenu(void) {
	printf("\n=== �̼����� �ѻ� ����! ===\n");
	printf("1. Toggle ���� �غ�\n");
	printf("2. Toggle ���� ���\n");
	printf("3. Toggle ���� ����\n");
	printf("4. Toggle ���� �غ�\n");
	printf("5. Toggle ������ ����\n");
	printf("6. Toggle �λ� �ļ�\n");
	printf("7. Toggle ���� ���\n");
	printf("8. Reset ALL (�ʱ�ȭ)\n");
	printf("9. Inspection (�ѹ��� ����)\n");
	printf("10. Full Attack Mode (���� ����)\n");
	printf("11. Exit\n");
	printf("��� ���� (1~11): ");
}

int main(void) {
	unsigned char fleet = 0;
	int choice;
	int hp = 100;

	
	while (1) {
		if (hp <= 0) {
			printf("�Լ��� ü���� ���Ǿ����ϴ�! ������ �����մϴ�\n");
			return 0;
		}
		printMenu(); // ���߿�
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			if (fleet & CMD_RELOAD) {
				fleet = CommandOff(fleet, 0);
				printf("HP:%d\n", hp);
				printf("���� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 0);
				printf("HP:%d\n", hp);
				printf("�� �Լ�, ǥ�� �����϶�!\n");
			}
			break;
		case 2:
			if (fleet & CMD_FIRE) {
				fleet = CommandOff(fleet, 1);
				printf("HP:%d\n", hp);
				printf("���� ����! ���� ������!\n");
			}
			else {
				fleet = CommandOn(fleet, 1);
				printf("HP:%d\n", hp);
				printf("���� �϶�! ���� ���� ����!\n");
			}
			break;
		case 3:
			if (fleet & CMD_CHARGE) {
				fleet = CommandOff(fleet, 2);
				printf("HP:%d\n", hp);
				printf("���� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 2);
				printf("HP:%d\n", hp);
				printf("�� �Լ� ���� ���� ����!\n");
			}
			break;
		case 4:
			if (fleet & CMD_HOLD) {
				fleet = CommandOff(fleet, 3);
				printf("HP:%d\n", hp);
				printf("���� ��� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 3);
				printf("HP:%d\n", hp);
				printf("���� �غ�, �� ������ ����!\n");
			}
			break;
		case 5:
			if (fleet & CMD_CRANE_FORM) {
				fleet = CommandOff(fleet, 4);
				printf("HP:%d\n", hp);
				printf("������ ���� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 4);
				printf("HP:%d\n", hp);
				printf("������ ���� ����!\n");
			}
			break;
		case 6:
			if (fleet & CMD_EVAC) {
				fleet = CommandOff(fleet, 5);
				printf("HP:%d\n", hp);
				printf("�λ� �ļ� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 5);
				hp=hp+5;
				printf("HP:%d\n", hp);
				printf("�λ� �ļ� ����!\n");
			}
			break;
		case 7:
			if (fleet & CMD_DAMAGE) {
				fleet = CommandOff(fleet, 6);
				printf("HP:%d\n", hp);
				printf("���� ��� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 6);
				hp = hp - 10;
				printf("HP:%d\n", hp);
				printf("�Լ� ���� �߻� ���!\n");
			}
			break;
		case 8:
			fleet = 0;
			printf("��� �Լ� ���� �ʱ�ȭ �Ϸ�!\n");
			printf("HP:%d\n", hp);
			break;
		case 9:
			printf("�ѹ��� ����: ���� ��� �Լ� ���� Ȯ��!\n");
			printf("HP:%d\n", hp);
			break;
		case 10:
			fleet = 0x7F; // ��� ��Ʈ ON
			printf("���� ���� ���! ��� ��� Ȱ��!\n");
			printf("HP:%d\n", hp);
			break;
		case 11:
			printf("���θ��� �����ݴϴ�.\n");
			printf("HP:%d\n", hp);
			return 0;
		default:
			printf("�߸��� �Է��Դϴ�! (1~11)����!\n");
		} // switch()

		showStatus(fleet);

	} // while()

	return 0;
}