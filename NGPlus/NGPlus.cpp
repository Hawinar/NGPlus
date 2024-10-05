#include <iostream>;
#include <windows.h>;
#include <math.h>
#include <cstring>
#include <string.h>
#include <string>


using namespace std;

/// <summary>
/// ������ ����������������, ���, ������� 2, � ����
/// </summary>

void Einstein()
{
    cout << "������� ����� ����� � ���������� (� �������� 100-400):" << endl;
    double waveLenght;
    cin >> waveLenght;
    if (waveLenght > 400 || waveLenght < 100)
        cout << "����� ����� ��� ���������� ���������, �������� ���������� �� ����������������." << endl;

    double h = 6.626 * pow(10, -34); // ���������� ������ (��*�)
    double c = (3.0 * pow(10, 8)); // �������� ����� (�/c)
    double lambda = (waveLenght) * pow(10, -9); // ����� ����� (�)
    double A = 2.26 * 1.602 * pow(10, -19); // ������ ������, � ����� ��� 2.26 ��, ��������� ��� � ������
    cout << "������������ ������������ �������: " << (((h * c) / (lambda)) - A) << " ��." << endl;

}

void Coords() 
{
    double x, y;
    cout << "������� x ���������� �����: " << endl;
    cin >> x;
    cout << "������� y ���������� �����: " << endl;
    cin >> y;

    if ((-1 <= x && x <= 1) && (-1 <= y && y <= 1))
    {
        if (abs(x) >= abs(y))
            cout << "���� ���������!" << endl;
        
        else
            cout << "������!" << endl;
    }
    else
        cout << "��� ���� �� ������." << endl;

}

void FirstNegative() 
{
    int n = 1;
    double u;
    while (true) {
         u = cos(tan(n) / 2);
         if(u < 0)
         {
             cout <<"������ ������ ������������� ���� ������������������: " << u << ", �� ��� ������� " << n << endl;
             break;
         }
         n++;
    }
}

void InArray() {
    // ���� �� ����� ���� ������������ vector, �� � ��������� �� � ������������ �������� n
    const int n = 6;
    float mult = 1;

    float nums[n];
    for (int i = 0; i < size(nums); i++) {
        cout << "������� ������� �" << i << ": " << endl;
        cin >> nums[i];
        if (i % 2 == 0)
            mult *= nums[i];
    }

    int first = -1;
    int last = -1;

    for(int i = 0; i < size(nums); i++)
    {
        if (nums[i] == 0) {
            if (first == -1)
                first = i;
            if (last < i)
                last = i;
        }
    }
    float sum = 0;
    if(first != -1)
    {
        for (int i = first; i <= last;i++)
            sum += nums[i];
    }
    // ���������� ���������
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (nums[j] < nums[j + 1]) {
                float temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }

    cout << "������������ ��������� ������� � ������� ��������: " << mult << endl;
    cout << "����� ��������� �������, ������������� ����� ������ � ��������� �������� ����������: " << sum << endl;
    cout << "��������������� ������: ";
    for (int i = 0; i < size(nums);i++)
        cout << nums[i] << " ";
    cout << endl;
}
void Matrix()
{
    const int n = 3;
    const int m = 4;

    int noZeroRows = 0;

    int matrix[n][m];
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m; j++) {
            cout <<"������: " << i << ", �������: " << j << ". ������� ������������� ��������: ";
            cin >> matrix[i][j];
        }
    }

    int max = INT_MIN;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m; j++) 
        {
            for (int r = 0; r < n;r++)
            {
                for (int c = 0; c < m; c++) {
                    if (i != r && c != j) {
                        if (matrix[i][j] == matrix[r][c] && matrix[i][j] > max)
                            max = matrix[i][j];
                    }
                }
            }
        }
    }
    bool noZero = true;
    for (int i = 0; i < n; i++)
    {
        noZero = true;
        for (int j = 0; j < m; j++) 
        {
            if (matrix[i][j] == 0)
                noZero = false;
        }
        if (noZero == false)
            noZeroRows++;
    }

    cout << "������� ��� ������� ���������: " << noZeroRows << endl;
    cout << "������������ ����������� ��������: " << max << endl;

}

string Swapper(string line)
{
    // ����������, ��� � ������ �� ����� 100 ��������.
    string limitedLine = "";
    int dividersCount = 0;
    int limit = line.length() > 100 ? 100 : line.length();
    for (int i = 0; i < limit; i++) {
        limitedLine += line[i];
    }

    // �������� � ������ 100 �������� -> �������� 100 ��������
    int dividres[100];
    

    for (int i = 0; i < line.length();i++) {
        if (line[i] == ' ')
        {
            dividres[dividersCount] = i;
            dividersCount++;
        }
    }
    // ���������� � word1 - ����� �� limitedLine, ������� 0 ��������
    int beginFrom = 0;
    string word1 = "";
    string word2 = "";

    string result = "";

    if (dividersCount > 0)
    {
        // ����������� �� �������
        for(int i = 0; i < dividersCount;) 
        {
            // �������� ������ �����
            for(int j = beginFrom; j <= dividres[i]; j++)
            {
                word1 += limitedLine[j];
            }
            // ���� ����� ������ ����� ����� ���� ���� ��� ������
            if(i + 1 < dividersCount)
            {
                // �������� ������ �����
                for (int j = dividres[i]+1; j <= dividres[i+1]; j++)
                {
                    word2 += limitedLine[j];
                }
                result += (word2 + word1);
                // � ��������� ��� ������ ����� ����� ��������� ������� � ������� �����
                beginFrom = dividres[i + 1]+1;
                i += 2;
            }
            // ���� ��� ����� - ���������, �� ����������
            else
            {
                for (int k = dividres[dividersCount-1]+1; k < limitedLine.length(); k++)
                {
                    word2 += limitedLine[k];
                }
                result += (word2 + " " + word1);
                beginFrom = line.length();
                // ������� ���������� ����� - ��������� ����
                break;
            }
            word1 = "";
            word2 = "";
        }
        // ���� �� �������� ���� ���� ����� ��� ����, �� ������ ���������� ���
        if(beginFrom < line.length())
        {
            for (int p = beginFrom; p < line.length(); p++)
            {
                word1 += limitedLine[p];
            }
            result += word1;
        }
        return result;
    }
    // ���� ���������� ��� ���� 1 ����� (����������� �� ������), �� ��������� ������ 100 �������� ��������� ������
    else
    {
        return limitedLine;
    }
}

void SwapInit()
{
    string str1, str2;
    cin.ignore();
    cout << "������� ������ ������ (�� ����� 100 ��������): ";
    getline(std::cin, str1);

    cout << "������� ������ ������ (�� ����� 100 ��������): ";
    getline(std::cin, str2);

    cout << "������ ������ ����� ���������: " << Swapper(str1) << endl;
    cout << "������ ������ ����� ���������: " << Swapper(str2) << endl;
}
   

void Geom() 
{
    double a, b, h, r, f;
    cout << "������� ����� ������, ������� ������� ���� �����: \n1 - �������������\n2 - ����������� (�������������)\n3 - �����������\n4 - ����\n5 - ������ �����" << endl;
    int choose;
    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "S = ab\n������� a: ";
        cin >> a;
        cout << "������� b: ";
        cin >> b;
        cout << "S = " << a*b << endl;
        break;

    case 2:
        cout << "S = (ab)/2\n������� a: ";
        cin >> a;
        cout << "������� b: ";
        cin >> b;
        cout << "S = " << (a * b)/2 << endl;
        break;

    case 3:
        cout << "S = (h(a+b))/2\n������� a: ";
        cin >> a;
        cout << "������� b: ";
        cin >> b;
        cout << "������� h: ";
        cin >> h;
        cout << "S = " << (h*(a + b))/2.0 << endl;
        break;

    case 4:
        cout << "S = pr^2\n������� r: ";
        cin >> r;
        cout << "S = " << 3.14 * pow(r,2.0) << endl;
        break;

    case 5:
        cout << "S = (pr^2*f)/360\n������� r: ";
        cin >> r;
        cout << "������� f: ";
        cin >> f;
        cout << "S = " << (3.14 * pow(r,2.0) * f) / 360 << endl;
        break;

    default:
        cout << "����� ����� �� �������������";
        break;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Einstein();
    Coords();
    FirstNegative();
    InArray();
    Matrix();
    SwapInit();
    Geom();
}