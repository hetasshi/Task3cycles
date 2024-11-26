#include <iostream>
#include <cmath>
using namespace std;

// Задание 1
void task1(double k, double p, double r) {
    double debt = k;
    int years = 0;

    while (debt > 0) {
        debt = debt + debt * (p / 100) - r;
        years++;

        if (years > 100) {
            cout << "Кредит невозможно погасить." << endl;
            return;
        }
    }

    cout << "Кредит можно погасить через " << years << " лет." << endl;
}

// Задание 2
void task2() {
    double time1, time2, time3;
    double totalTime = 0;

    cout << "Введите длительности обработки на каждом из трех станков (группами по 3 числа, -1 для завершения ввода):" << endl;
    while (true) {
        cin >> time1;
        if (time1 == -1) break;
        cin >> time2 >> time3;
        totalTime += (time1 + time2 + time3);
    }

    cout << "Общее время обработки всех деталей: " << totalTime << " единиц." << endl;
}

// Задание 3
void task3(double T) {
    double t, l;
    double currentTime = 0;
    int clientsServed = 0;

    cout << "Введите момент прихода и продолжительность обслуживания клиентов (2 числа, -1 для завершения):" << endl;
    while (true) {
        cin >> t;
        if (t == -1) break;
        cin >> l;

        if (currentTime <= t) {
            currentTime = t + l;
            if (currentTime <= T) {
                clientsServed++;
            } else {
                break;
            }
        }
    }

    cout << "Клиентов обслужено: " << clientsServed << endl;
    cout << "Затраченное время на обслуживание: " << (currentTime > T ? T : currentTime) << " единиц." << endl;
}

// Задание 4
void task4(double u, double v, double w, int k, double s, double t, double f, double p, double q, double r, double x) {
    int days = 0;

    while (true) {
        double dailyHay = k * u;
        double dailySilage = k * v;
        double dailyFeed = k * w;

        if (s < dailyHay || t < dailySilage || f < dailyFeed) {
            cout << "На " << days << " день закончится корм." << endl;

            if (s < dailyHay) cout << "Первым закончится сено." << endl;
            else if (t < dailySilage) cout << "Первым закончится силос." << endl;
            else cout << "Первым закончится комбикорм." << endl;
            break;
        }

        s -= dailyHay;
        t -= dailySilage;
        f -= dailyFeed;

        k = k - static_cast<int>(ceil(k * (p / 100.0)));
        s -= s * (q / 100.0);
        t -= t * (r / 100.0);
        f -= f * (x / 100.0);

        days++;
    }
}

int main() {
    int choice;

    cout << "Выберите задание (1-4):" << endl;
    cin >> choice;

    switch (choice) {
        case 1: {
            double k, p, r;
            cout << "Введите сумму кредита (k), процентную ставку (p) и годовую прибыль (r):" << endl;
            cin >> k >> p >> r;
            task1(k, p, r);
            break;
        }
        case 2:
            task2();
            break;
        case 3: {
            double T;
            cout << "Введите длительность смены (T):" << endl;
            cin >> T;
            task3(T);
            break;
        }
        case 4: {
            double u, v, w, s, t, f, p, q, r, x;
            int k;

            cout << "Введите рацион коровы (u, v, w), число коров (k), остатки кормов (s, t, f), потери (p, q, r, x):" << endl;
            cin >> u >> v >> w >> k >> s >> t >> f >> p >> q >> r >> x;
            task4(u, v, w, k, s, t, f, p, q, r, x);
            break;
        }
        default:
            cout << "Некорректный выбор!" << endl;
    }

    return 0;
}
