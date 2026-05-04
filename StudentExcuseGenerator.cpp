#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ExcuseGenerator {
private:
    string name;
    vector<string> excuses;

    // Custom deterministic "random" function (no stdlib randomness)
    int generateIndex() {
        int seed = name.length();

        // Mix character values into seed
        for (char c : name) {
            seed += (int)c;
        }

        // Extra mixing for variation
        for (int i = 0; i < 10; i++) {
            seed = (seed * 3 + 7) % 1000;
        }

        return seed % excuses.size();
    }

    // Replace {name} with actual student name
    string replaceName(string text) {
        size_t pos = text.find("{name}");

        while (pos != string::npos) {
            text.replace(pos, 6, name);
            pos = text.find("{name}");
        }

        return text;
    }

public:
    // Constructor
    ExcuseGenerator(string studentName) {
        name = studentName;

        // Store excuse templates
        excuses = {
            "{name} couldn't finish homework because the laptop started updating for 6 hours.",
            "{name} was ready to submit but Wi-Fi mysteriously disappeared.",
            "{name} tried studying but the textbook turned into memes.",
            "{name} lost motivation after opening the assignment.",
            "{name} got distracted by an emergency snack mission.",
            "{name}'s pen stopped working at the worst possible time.",
            "{name} accidentally submitted homework to another universe.",
            "{name} planned to study but the bed won the argument.",
            "{name}'s laptop decided to restart its life choices.",
            "{name} started homework but procrastination took over."
        };
    }

    // Function to display excuse
    void showExcuse() {
        int index = generateIndex();
        string excuse = replaceName(excuses[index]);

        cout << "\nGenerated Homework Excuse:\n";
        cout << excuse << endl;
    }
};

int main() {
    string studentName;

    // Input name
    cout << "Enter student name: ";
    getline(cin, studentName);

    // Create object
    ExcuseGenerator generator(studentName);

    // Show excuse
    generator.showExcuse();

    return 0;
}