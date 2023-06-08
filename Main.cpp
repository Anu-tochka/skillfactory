#include <iostream>
#include "PipleTree.h"

int main(char* ar[], int count)
{
    PipleTree sn;

    sn.add("Олег");
    sn.add("Никита");
    sn.add("Настя");
    sn.add("Ваня");
    sn.add("Женя");

    sn.addFriendship("Олег", "Никита");
    sn.addFriendship("Никита", "Настя");
    sn.addFriendship("Настя", "Ваня");
    sn.addFriendship("Ваня", "Женя");

    sn.showThreeHandshakes();

    return 0;
}
