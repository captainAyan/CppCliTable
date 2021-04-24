
#include <iostream>
#include <map>
#include "table.h"

int main() {

  std::string r[3][3] = {
    {"Samuel Miller", "Coding Memes", "Venezuela"},
    {"DevEd", "Web Development", "Germany"},
    {"Mykull", "Crack Head", "U.S.A"}
  };

  Table table;
  Column c[3] = {
    Column("Name", Column::CENTER_ALIGN, Column::LEFT_ALIGN, 1,7, Column::NON_RESIZABLE),
    Column("Topic", Column::CENTER_ALIGN, Column::RIGHT_ALIGN, 1,2, Column::RESIZABLE),
    Column("Nation", Column::CENTER_ALIGN, Column::LEFT_ALIGN, 1,5, Column::NON_RESIZABLE)};

  for (int i = 0; i < 3; i++) {
    table.addColumn(c[i]);
  }

  for (int i = 0; i < 3; i++) {
    table.addRow(r[i]);
  }
  table.draw();

  return EXIT_SUCCESS;
}