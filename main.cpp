
#include <iostream>
#include <map>
#include "table.h"

int main() {

  std::string r[3][3] = {
    {"Samuel Miller", "Coding Memes", "Venezuela"},
    {"DevEd", "Web Development", "Germany"},
    {"Mykull", "Crack Head", "U.S.A"}
  };

  clitable::Table table;
  clitable::Column c[3] = {
    clitable::Column("Name", clitable::Column::CENTER_ALIGN, clitable::Column::LEFT_ALIGN, 1,7, clitable::Column::NON_RESIZABLE),
    clitable::Column("Topic", clitable::Column::CENTER_ALIGN, clitable::Column::RIGHT_ALIGN, 1,2, clitable::Column::RESIZABLE),
    clitable::Column("Nation", clitable::Column::CENTER_ALIGN, clitable::Column::LEFT_ALIGN, 1,5, clitable::Column::NON_RESIZABLE)};

  table.addTitle("These Are YOUTUBERS");

  for (int i = 0; i < 3; i++) {
    table.addColumn(c[i]);
  }

  for (int i = 0; i < 3; i++) {
    table.addRow(r[i]);
  }
  table.draw();

  return EXIT_SUCCESS;
}