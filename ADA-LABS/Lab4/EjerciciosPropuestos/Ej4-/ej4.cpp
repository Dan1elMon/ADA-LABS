#include <iostream>
#include <string>
#include <vector>

void insertionSortStrings(std::vector<std::string>& v) {
    for (int j = 1; j < v.size(); ++j) {
        std::string x = v[j];
        int i;
        for (i = j - 1; i >= 0 && v[i] > x; --i) {
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}

int main() {
    using namespace std;

    vector<string> strings = {"buitre", "canguro", "aguila", "gato", "llama"};

    cout << "Strings original:" << endl;
    for (const string& s : strings) {
        cout << s << " ";
    }
    cout << endl;

    insertionSortStrings(strings);

    cout << "Strings ordenado:" << endl;
    for (const string& s : strings) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
