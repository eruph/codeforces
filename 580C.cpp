#include <iostream>
#include <vector>
using namespace std;

vector<int> values;
vector<vector<int>> tree;
int m; // максимальное количество подряд идущих вершин с котами
int answer = 0;

// прямая, нехвостовая рекурсия
void dfs(int v, int parent, int cats_count) {
    // если подряд идёт кот - увеличиваем счётчик, иначе цепочка прерывается, сбрасываем счётчик в 0
    if (values[v] == 1) {
        cats_count++;
    } else {
        cats_count = 0;
    }

    // удовлетворяет ли текущий маршрут заданному максимальному количеству подряд идущих котов
    if (cats_count > m)
        return;

    bool is_leaf = true;
    for (int neighbor : tree[v]) {
        if (neighbor == parent)
            continue;

        is_leaf = false;
        dfs(neighbor, v, cats_count);
    }

    if (is_leaf)
        answer++;

}

int main(){
    int n = 0; // кол-во вершин
    cin >> n >> m; 

    values.resize(n+1); // n(i) - признак наличия кота в вершине n, 1 - есть, 0 - нет
    for (int i = 1; i < (n+1); ++i) {
        int a = 0; // признак наличия кота
        cin >> a;
        values[i] = a;
    }

    tree.resize(n + 1);
    for(int i = 1; i < n; ++i){
        int x = 0;
        cin >> x;
        int y = 0;
        cin >> y;
        tree[x].push_back(y);
        tree[y].push_back(x); // неориентированное дерево, добавляем маршрут обратно
    }

    dfs(1, 0, 0);

    cout << answer << "\n";

    return 0;
}
