#include <iostream>

using namespace std;

union FloatBytes {
	float val;
	unsigned char bytes[sizeof(float)];
};

// ����� ������ �����
void PrintMemoryRepresentation(unsigned char obj) {
	unsigned char n = 1;
	n = n << 7;
	// ������ 1 � ����� ����� ������
	unsigned char s;

	for (int i = 0; i < 8; i++) {
		s = obj & n; // ���� � obj ���� ������� � (7-i)-�� �������, ���������� 128; ���� ��� ����, �� ���������� 0
		cout << (unsigned int)s / 128;
		obj = obj << 1;
	}
}

// ����� ����� �� ������ (unsigned char) ����� ����������
void PrintMemoryRepresentation(char obj) {
	PrintMemoryRepresentation((unsigned char)obj);
}

void PrintMemoryRepresentation(float obj) {
	FloatBytes floatBytes;
	floatBytes.val = obj;

	for (int i = sizeof(float) - 1; i >= 0; i--) { // ������� ������ ����
		PrintMemoryRepresentation(floatBytes.bytes[i]);
		cout << " ";
	}
}

bool CopyBit(unsigned char obj, int bitPos) {
	unsigned char t = 1;
	t = t << bitPos; // ������ 1 ��� ��� ������� ����� �����������
	return (obj & t) != 0;
}

unsigned char CreateByteWithInsertedBit(unsigned char obj, bool bit, int bitPos) {
	unsigned char t;
	t = 1;
	t = t << bitPos; // ������ 1 ��� ��� ������� ����� ��������

	if (bit) { // ���� ���� �������� 1
		obj = obj | t;
	}
	else { // ���� ���� �������� 0
		obj = obj & ~t;
	}
	return obj;
}

bool CopyBit(FloatBytes& obj, int bitPos) {
	int bytePos = bitPos / 8; // ����� �� ���-�� ��� � �����
	int bitPosInByte = bitPos % 8;
	return CopyBit(obj.bytes[bytePos], bitPosInByte);
}

void InsertBit(FloatBytes& obj, bool bit, int bitPos) {
	int bytePos = bitPos / 8; // ����� �� ���-�� ��� � �����
	int bitPosInByte = bitPos % 8;
	unsigned char newByte = CreateByteWithInsertedBit(obj.bytes[bytePos], bit, bitPosInByte);
	obj.bytes[bytePos] = newByte;
}

void SwapBits(FloatBytes& obj, int bitPos1, int bitPos2) {
	bool t = CopyBit(obj, bitPos1);
	InsertBit(obj, CopyBit(obj, bitPos2), bitPos1);
	InsertBit(obj, t, bitPos2);
}

float InsertBitGroup(float obj, int bitPos, int amountOfBits, char* bits)
{
#pragma region Exceptions
	if (bitPos < 0 || bitPos > sizeof(float) * 8 - 1)
	{
		throw exception("������� ������ ��������� ������");
	}
	if (bitPos + amountOfBits - 1 > sizeof(float) * 8 - 1)
	{
		throw exception("�������� ������ ������");
	}
	for (int i = 0; i < 32 && bits[i] != '\0'; i++)
	{
		if (bits[i] != '0' && bits[i] != '1')
		{
			throw exception("������� ������� ����");
		}
	}
#pragma endregion

	FloatBytes floatBytes;
	floatBytes.val = obj;

	for (int i = 0; i < amountOfBits; i++)
	{
		bool bit;
		switch (bits[i])
		{
		case '0': bit = false; break;
		case '1': bit = true; break;
		}
		InsertBit(floatBytes, bit, bitPos + (amountOfBits - 1) - i);
	}

	return floatBytes.val;
}

int main() {
	setlocale(LC_ALL, "");

	unsigned char c;
	float f;
	int bitPos, sizeOfGroup;
	char bits[33];

	try
	{
		cout << "������� unsigned char(���� ������): ";
		cin >> c;
		if (cin.fail()) throw exception("������");

		cout << "������� float: ";
		cin >> f;
		if (cin.fail()) throw exception("������");
		cout << endl << "������������� unsigned char � ������ ����������: " << endl;
		PrintMemoryRepresentation(c);

		cout << endl << "������������� float � ������ ����������: " << endl;
		PrintMemoryRepresentation(f);

		cout << endl << endl;

		cout << "�������������� ��� float\n������� ��������� ������:";
		cin >> bitPos;
		if (cin.fail()) throw exception("������");
		cout << "������� ���������� ���: ";
		cin >> sizeOfGroup;
		if (cin.fail()) throw exception("������");
		cout << "������� " << sizeOfGroup << " ���: ";

		cin.ignore();
		cin.getline(bits, sizeOfGroup + 1);
		if (cin.fail()) throw exception("������");
	}
	catch (exception ex)
	{
		cout << endl << "Exception: " << ex.what() << endl;
		return 0;
	}

	float n;
	try
	{
		n = InsertBitGroup(f, bitPos, sizeOfGroup, bits);
	}
	catch (exception ex)
	{
		cout << endl << "Exception: " << ex.what() << endl;
		return 0;
	}

	cout << endl << "float �� ��������������: " << f << endl;
	PrintMemoryRepresentation(f);
	cout << endl << "float ����� ��������������: " << n << endl;
	PrintMemoryRepresentation(n);

	return 0;
}