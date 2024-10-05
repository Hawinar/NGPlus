#include <iostream>;
#include <windows.h>;
#include <math.h>
#include <cstring>
#include <string.h>
#include <string>


using namespace std;

/// <summary>
/// Основы программирования, ВПИ, вариант 2, к зиме
/// </summary>

void Einstein()
{
    cout << "Введите длину волны в нанометрах (в пределах 100-400):" << endl;
    double waveLenght;
    cin >> waveLenght;
    if (waveLenght > 400 || waveLenght < 100)
        cout << "Длина волны вне указанного диапазона, возможно отхождение от действительности." << endl;

    double h = 6.626 * pow(10, -34); // Постоянная Планка (Дж*с)
    double c = (3.0 * pow(10, 8)); // Скорость света (м/c)
    double lambda = (waveLenght) * pow(10, -9); // Длина волны (м)
    double A = 2.26 * 1.602 * pow(10, -19); // Работа выхода, у калия это 2.26 эВ, переводим это в Джоули
    cout << "Максимальная кинетическая энергия: " << (((h * c) / (lambda)) - A) << " Дж." << endl;

}

void Coords() 
{
    double x, y;
    cout << "Введите x координату точки: " << endl;
    cin >> x;
    cout << "Введите y координату точки: " << endl;
    cin >> y;

    if ((-1 <= x && x <= 1) && (-1 <= y && y <= 1))
    {
        if (abs(x) >= abs(y))
            cout << "Есть попадание!" << endl;
        
        else
            cout << "Промах!" << endl;
    }
    else
        cout << "Это даже не близко." << endl;

}

void FirstNegative() 
{
    int n = 1;
    double u;
    while (true) {
         u = cos(tan(n) / 2);
         if(u < 0)
         {
             cout <<"Найден первый отрицательный член последовательности: " << u << ", он под номером " << n << endl;
             break;
         }
         n++;
    }
}

void InArray() {
    // Если бы можно было использовать vector, то я спрашивал бы у пользователя значение n
    const int n = 6;
    float mult = 1;

    float nums[n];
    for (int i = 0; i < size(nums); i++) {
        cout << "Введите элемент №" << i << ": " << endl;
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
    // Сортировка пузырьком
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (nums[j] < nums[j + 1]) {
                float temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }

    cout << "Произведение элементов массива с чётными номерами: " << mult << endl;
    cout << "Сумма элементов массива, расположенных между первым и последним нулевыми элементами: " << sum << endl;
    cout << "Отсортированный массив: ";
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
            cout <<"Строка: " << i << ", столбец: " << j << ". Введите целочисленное значение: ";
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

    cout << "Строчек без нулевых элементов: " << noZeroRows << endl;
    cout << "Максимальное повторяющее значение: " << max << endl;

}

string Swapper(string line)
{
    // Убеждаемся, что в строке не более 100 символов.
    string limitedLine = "";
    int dividersCount = 0;
    int limit = line.length() > 100 ? 100 : line.length();
    for (int i = 0; i < limit; i++) {
        limitedLine += line[i];
    }

    // Максимум в строке 100 символов -> максимум 100 пробелов
    int dividres[100];
    

    for (int i = 0; i < line.length();i++) {
        if (line[i] == ' ')
        {
            dividres[dividersCount] = i;
            dividersCount++;
        }
    }
    // Изначально в word1 - текст из limitedLine, начиная 0 элемента
    int beginFrom = 0;
    string word1 = "";
    string word2 = "";

    string result = "";

    if (dividersCount > 0)
    {
        // Пробегаемся по запятым
        for(int i = 0; i < dividersCount;) 
        {
            // Получаем первое слово
            for(int j = beginFrom; j <= dividres[i]; j++)
            {
                word1 += limitedLine[j];
            }
            // Если слово дальше будет иметь свою пару для обмена
            if(i + 1 < dividersCount)
            {
                // Получаем второе слово
                for (int j = dividres[i]+1; j <= dividres[i+1]; j++)
                {
                    word2 += limitedLine[j];
                }
                result += (word2 + word1);
                // В следующий раз первое слово будем считывать начиная с другого места
                beginFrom = dividres[i + 1]+1;
                i += 2;
            }
            // Если это слово - последнее, то дописываем
            else
            {
                for (int k = dividres[dividersCount-1]+1; k < limitedLine.length(); k++)
                {
                    word2 += limitedLine[k];
                }
                result += (word2 + " " + word1);
                beginFrom = line.length();
                // Дописав оставшийся текст - прерываем цикл
                break;
            }
            word1 = "";
            word2 = "";
        }
        // Если же осталось лишь одно слово без пары, то просто дописываем его
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
    // Если изначально тут лишь 1 слово (разделитель не найден), то вовращаем первые 100 символов исходного текста
    else
    {
        return limitedLine;
    }
}

void SwapInit()
{
    string str1, str2;
    cin.ignore();
    cout << "Введите первую строку (не более 100 символов): ";
    getline(std::cin, str1);

    cout << "Введите вторую строку (не более 100 символов): ";
    getline(std::cin, str2);

    cout << "Первая строка после обработки: " << Swapper(str1) << endl;
    cout << "Вторая строка после обработки: " << Swapper(str2) << endl;
}
   

void Geom() 
{
    double a, b, h, r, f;
    cout << "Введите номер фигуры, площадь которой надо найти: \n1 - прямоугольник\n2 - треугольник (прямоугольный)\n3 - треугольник\n4 - круг\n5 - сектор круга" << endl;
    int choose;
    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "S = ab\nВведите a: ";
        cin >> a;
        cout << "Введите b: ";
        cin >> b;
        cout << "S = " << a*b << endl;
        break;

    case 2:
        cout << "S = (ab)/2\nВведите a: ";
        cin >> a;
        cout << "Введите b: ";
        cin >> b;
        cout << "S = " << (a * b)/2 << endl;
        break;

    case 3:
        cout << "S = (h(a+b))/2\nВведите a: ";
        cin >> a;
        cout << "Введите b: ";
        cin >> b;
        cout << "Введите h: ";
        cin >> h;
        cout << "S = " << (h*(a + b))/2.0 << endl;
        break;

    case 4:
        cout << "S = pr^2\nВведите r: ";
        cin >> r;
        cout << "S = " << 3.14 * pow(r,2.0) << endl;
        break;

    case 5:
        cout << "S = (pr^2*f)/360\nВведите r: ";
        cin >> r;
        cout << "Введите f: ";
        cin >> f;
        cout << "S = " << (3.14 * pow(r,2.0) * f) / 360 << endl;
        break;

    default:
        cout << "Такая опция не предусмотрена";
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