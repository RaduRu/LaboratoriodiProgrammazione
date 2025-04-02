#include <iostream>
#include "ShoppingList.h"
#include "ShoppingItem.h"
#include "User.h"
using namespace std;

int main() {
    ShoppingList list("Spesa Settimanale", 10, 11, 2023);

    ShoppingItem item1("Latte", "Alimenti");
    ShoppingItem item2("Pane", "Alimenti");
    ShoppingItem item3("Detersivo", "Pulizie");

    list.addItem(item1, 2);
    list.addItem(item2, 3);
    list.addItem(item3, 1);

    cout << " --- Lista iniziale --- " << endl;
    cout << list.getName() << " (Data: 10/11/2023)" << endl;

    const auto &items = list.getItems();
    for (const auto &pair: items) {
        cout << "- " << pair.first.getName()
             << " (" << pair.first.getCategory()
             << "): " << pair.second << " pezzi" << endl;
    }

    cout << "\n--- Rimuovo item1 dalla lista ---" << endl;
    list.removeItem(item1);

    cout << "\n### Lista aggiornata ###" << endl;
    const auto &updatedItems = list.getItems();
    for (const auto &pair: updatedItems) {
        cout << "- " << pair.first.getName()
             << " (" << pair.first.getCategory()
             << "): " << pair.second << " pezzi" << endl;
    }

    cout << "\n--- Rimuovo item3 caso limite ---" << endl;
    list.removeItem(item3);

    cout << "\n### Lista aggiornata ###" << endl;
    const auto &updatedItems2 = list.getItems();
    for (const auto &pair: updatedItems) {
        cout << "- " << pair.first.getName()
             << " (" << pair.first.getCategory()
             << "): " << pair.second << " pezzi" << endl;
    }

    User user1("Marta");
    User user2("Luca");
    User user3("Pino");

    list.subscribe(&user1);
    list.subscribe(&user2);
    list.subscribe(&user3);

    cout << "\n--- Utenti iscritti inizialmente ---" << endl;
    cout << user1.getID() << " è iscritto." << endl;
    cout << user2.getID() << " è iscritto." << endl;
    cout << user3.getID() << " è iscritto." << endl;

    cout << "\n---  L'utente Luca si è rimosso dalla lista ---" << endl;
    list.unsubscribe(&user2);



    cout << "\n--- Aggiungendo 'Frutta' alla lista ---" << endl;

    ShoppingItem item4("Frutta", "Alimenti");
    list.addItem(item4, 5); 

    cout << "\n### Notifica agli utenti aggiornati ###" << endl;
    user1.update();
    user3.update();

    return 0;
}