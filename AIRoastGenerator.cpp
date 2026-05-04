#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "{name} is proof that even bugs need a home.",
        "{name}'s code has more errors than a math exam.",
        "{name} debugs by deleting the whole program.",
        "{name} makes infinite loops look intentional.",
        "{name}'s logic is like WiFi in a basement — weak.",
        "{name} once tried to compile emotions and failed.",
        "{name} writes comments like they're plot twists.",
        "{name} thinks 'Hello World' is a big achievement.",
        "{name}'s code works... only in dreams.",
        "{name} uses Google more than the compiler.",
        "{name} turns simple problems into PhD research."
    };

    int seed = name.length() * 7 + 3;
    int randomIndex = seed % roasts.size();

    string selected = roasts[randomIndex];

    size_t pos = selected.find("{name}");
    while (pos != string::npos) {
        selected.replace(pos, 6, name);
        pos = selected.find("{name}");
    }

    cout << selected << endl;

    return 0;
}