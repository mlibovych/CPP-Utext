#include "pieceTable.h"

#include <iostream>

// class pieceTable {
    // const char *m_original;
    // char *m_added;
    // vector<tuple<int, int, bool>> m_pieces; // start, length, source
    // int m_added_size;
    // int m_added_capacity;

// public:
//     pieceTable();
//     pieceTable(const std::string& original);
//     ~pieceTable();

//     char *getText() const;
//     bool addText(char *str, int index, int len);
// };

pieceTable::pieceTable() : m_original(nullptr), m_orig_size(0) {
    init_variables();
}

pieceTable::pieceTable(const std::string& original) {
    int len = 0;
    m_original = strdup(original, &len);
    m_orig_size = len;
    init_variables();
    m_pieces.push_back(Piece(0, original.length(), Source::orig));
}

void pieceTable::init_variables(void) {
    m_item = m_pieces.end();
    m_index = 0;
    m_item = m_pieces.begin();
    m_added = alloc_memory(16);
    m_added_size = 0;
    m_added_capacity = 16;
}

pieceTable::~pieceTable() {
    std::free((void *)m_original);
    std::free((void *)m_added);
}


// Utils block
char *pieceTable::strdup(const std::string& str, int *len) const {
    char *res = alloc_memory(str.size() + 1);
    int i = 0;

    for (const char& c : str)
        res[i++] = c;

    res[i] = '\0';
    *len = i;

    return res;
}

char *pieceTable::alloc_memory(int size) const {
    char *res = (char *)std::malloc(sizeof(char) * (size));

    if (res == nullptr)
        throw "alloc error";

    return res;
}

void pieceTable::realloc_added(int len) {
    int size = len > m_added_capacity ? len * 2 : m_added_capacity * 2;
    char *new_added = (char *)std::realloc(m_added, sizeof(char) * size);

    if (!new_added)
        throw "realloc error";

    m_added = new_added;
    m_added_capacity = size;
}


//Insert block
void pieceTable::addText(char *str, int index, int len) {
    list<Piece>::iterator piece = m_pieces.end();
    int index_counter = 0;

    if (index == 0) {
        m_pieces.push_front(Piece(m_added_size, len, Source::added));
        m_item = m_pieces.begin();
    }
    else if (index == m_orig_size + m_added_size)
        insertNode(--m_pieces.end(), str, len);
    else {
        for (auto it = m_pieces.begin(); it != m_pieces.end(); ++it) {
            index_counter += (*it).m_len;

            if (index_counter > index) {
                splitNode(piece, index_counter, str, index, len);
                break;
            }
            else if (index_counter == index) {
                insertNode(it, str, len);
                break;
            }
        }
    }

    if (m_added_capacity - m_added_size < len)
        realloc_added(len);

    std::memcpy((void *)(m_added + m_added_size), str, sizeof(char) * len);
    m_added_size += len;
}

void pieceTable::splitNode(list<Piece>::iterator it, int counter, char *str, int index, int len) {
    int node3_len = counter - index;
    int node1_len = (*it).m_len - node3_len;

    Piece node1((*it).m_start, node1_len, (*it).m_source);
    m_pieces.insert(it, node1);

    Piece node2(len, m_added_size, Source::added);
    m_pieces.insert(it, node2);

    (*it).m_len = node3_len;
    (*it).m_start += node1_len;
}

void pieceTable::insertNode(list<Piece>::iterator it, char *str, int len) {
    if ((*it).m_source == Source::added && (*it).m_start + (*it).m_len == m_added_size)
        (*it).m_len += len;
    else {
        Piece piece(*it);
        m_pieces.insert(it, piece);

        (*it).m_len = len;
        (*it).m_start = m_added_size;
        (*it).m_source = Source::added;
    }
}


// Retrieve block
char pieceTable::getChar(void) {
    if (m_item == m_pieces.end())
        return 0;
    else {
        char c = 0;
        if ((*m_item).m_source == Source::orig)
            c = m_original[(*m_item).m_start + m_index];
        else
            c = m_added[(*m_item).m_start + m_index];

        if (++m_index >= (*m_item).m_len) {
            m_index = 0;
            ++m_item;
        }
        return c;
    }
}

void pieceTable::resetIndex(void) {
    m_index = 0;
    m_item = m_pieces.begin();
}

bool pieceTable::setIndex(int index) {
    int counter = 0;

    for (auto it = m_pieces.begin(); it != m_pieces.end(); ++it) {
        counter += (*it).m_len;

        if (counter >= index) {
            m_item = it;
            m_index = counter - index;
            return true;
        }
    }

    return false;
}