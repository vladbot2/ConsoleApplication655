#include <iostream>
#include <iostream>

using namespace std;



class Vagon {
public:
    int number;
    int totalSeats;
    int passengers;

    Vagon() : number(0), totalSeats(0), passengers(0) {}

    Vagon(int num, int seats, int pass) : number(num), totalSeats(seats), passengers(pass) {}

    void Show() const {
        cout << "Vagon number: " << number << endl;
        cout << "Total seats: " << totalSeats << endl;
        cout << "Passengers: " << passengers << endl;
    }

    void AddPassenger() {
        if (passengers < totalSeats) {
            passengers++;
            cout << "1 passenger added. Now there are " << passengers << " passengers in the vagon." << endl;
        }
        else {
            cout << "The vagon is full, no more passengers can be added!" << endl;
        }
    }
};
class Train {
public:
    string model;
    int vagonCount;
    Vagon* vagons;

    Train(): vagonCount(0), vagons(nullptr) {}

    Train(string mod, int count) : model(mod), vagonCount(count) {
        vagons = new Vagon[vagonCount];
    }

    void AddVagon(Vagon newVagon) {
        Vagon* temp = new Vagon[vagonCount + 1];
        for (int i = 0; i < vagonCount; i++) {
            temp[i] = vagons[i];
        }
        temp[vagonCount] = newVagon;
        delete[] vagons;
        vagons = temp;
        vagonCount++;
    }

    void Show() const {
        cout << "Train model: " << model << endl;
        cout << "Number of vagons: " << vagonCount << endl;
        for (int i = 0; i < vagonCount; i++) {
            cout << "Vagon " << i + 1 << ":" << endl;
            vagons[i].Show();
        }
    }

    void AddPassengerToVagon(int vagonNumber) {
        if (vagonNumber >= 1 && vagonNumber <= vagonCount) {
            vagons[vagonNumber - 1].AddPassenger();
        }
        else {
            cout << "No such vagon exists!" << endl;
        }
    }

    Train(const Train& other) {
        model = other.model;
        vagonCount = other.vagonCount;
        vagons = new Vagon[vagonCount];
        for (int i = 0; i < vagonCount; i++) {
            vagons[i] = other.vagons[i];
        }
    }

    ~Train() {
        delete[] vagons;
    }
};
int main() {
    Train train("Model X", 2);
    train.AddVagon(Vagon(1, 50, 20));
    train.AddVagon(Vagon(2, 60, 30));

    train.Show();

    train.AddPassengerToVagon(1);
    train.AddPassengerToVagon(3);

}