#include <bits/stdc++.h>

using namespace std;

void distribute_apple()
{
    vector<int> v;
    int total_apple_weight = 0;
    for (int i = 1;; i++)
    {
        int apple_weight;
        cin >> apple_weight;
        if (apple_weight == -1)
            break;
        v.push_back(apple_weight);
        total_apple_weight += apple_weight;
    }

    // 400 100 400 300 200 300 100 200 -1
    int totalMoney = 100;
    int ramuShare = 50;
    int shyamShare = 30;
    int rahimShare = 20;

    int ramuTarget = (ramuShare * total_apple_weight) / totalMoney;
    int shyamTarget = (shyamShare * total_apple_weight) / totalMoney;
    int rahimTarget = (rahimShare * total_apple_weight) / totalMoney;
    sort(v.begin(), v.end(), greater<int>());
    int ram_total = 0, sham_total = 0, rahim_total = 0;
    vector<int> ram_apples;
    vector<int> sham_apples;
    vector<int> rahim_apples;

    for (int weight : v)
    {
        if (ram_total < ramuTarget && (ram_total <= sham_total && ram_total <= rahim_total))
        {
            ram_apples.push_back(weight);
            ram_total += weight;
        }
        else if (sham_total < shyamTarget && (sham_total <= ram_total && sham_total <= rahim_total))
        {
            sham_apples.push_back(weight);
            sham_total += weight;
        }
        else
        {
            rahim_apples.push_back(weight);
            rahim_total += weight;
        }
    }
    cout << "Ram: ";
    for (int w : ram_apples)
        cout << w << " ";
    cout << "(total " << ram_total << "g, 50%)" << endl;

    cout << "Sham: ";
    for (int w : sham_apples)
        cout << w << " ";
    cout << "(total " << sham_total << "g, 30%)" << endl;

    cout << "Rahim: ";
    for (int w : rahim_apples)
        cout << w << " ";
    cout << "(total " << rahim_total << "g, 20%)" << endl;
    return;
}
int main()
{
    distribute_apple();
    return 0;
}