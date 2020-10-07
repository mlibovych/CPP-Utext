#include "pieceTable.h"
#include <iostream>

ostream& operator<<(ostream& ss, const Piece& piece) {
    ss << "Start: " << piece.m_start << "; Len: " << piece.m_len << "; Source: ";

    if (piece.m_source == Source::orig)
        ss << "orig";
    else
        ss << "added";

    return ss;
}

ostream& operator<<(ostream& ss, const pieceTable& table) {
    ss << "*****************************" << std::endl;
    if (table.getOrig() != nullptr)
        ss << "orig: " << table.getOrig() << std::endl << std::endl;
    ss << "added: " << table.getAdded() << std::endl << std::endl;
    ss << table.getSize() << " " << table.getCapac() << std::endl << std::endl;

    std::list<Piece> list = table.getList();
    for (const auto& p : list)
        ss << p << std::endl << std::endl;

    ss << "*****************************" << std::endl;
    return ss;
}

int main() {
    // pieceTable p;
    // std::cout << p;

    pieceTable p2("Fox has jumped on the box!");
    p2.addText("\nThen it has eaten an ox!", 26, 25);
    p2.addText("\nIt started to think out of the box", 51, 35);
    p2.addText("A story about a fox.\n", 0, 21);

    p2.addText("\nSo the", 107, 7);
    p2.addText(" fox", 114, 4);
    p2.addText(" started wearing crocs", 118, 22);
    std::cout << p2;

    p2.addText(" lovely sly", 114, 11);

    p2.addText("By Yulia Bondarenko.\n", 21, 21);
    std::cout << p2;

    char c;
    while ((c = p2.getChar())) {
        std::cout << c;
    }
}
