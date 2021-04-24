#pragma once

#include <vector>
#include <iostream>
#include <string>

class Column {

  private:
  std::string _heading;
  short _heading_alignment, _column_alignment;
  unsigned int _padding, _size;
  bool _resizable;

  public:
  static const short LEFT_ALIGN = 1;
  static const short RIGHT_ALIGN = 2;
  static const short CENTER_ALIGN = 3;

  static const bool RESIZABLE = true;
  static const bool NON_RESIZABLE = false;

  Column(std::string heading, 
    short heading_alignment, 
    short column_alignment, 
    unsigned int padding,
    unsigned int size,
    bool resizable) {
    _heading = heading;
    _heading_alignment = heading_alignment;
    _column_alignment = column_alignment;
    _padding = padding;

    _size = size;
    if (_size == 0) _size = 1;

    _resizable = resizable;
    if(resizable && _heading.size() > _size) _size = _heading.length();
  }

  std::string getHeading() {return _heading;}
  short getHeadingAlignment() {return _heading_alignment;}
  short getColumnAlignment() {return _column_alignment;}
  unsigned int getPadding() {return _padding;}
  unsigned int getSize() {return _size;}
  bool isResizable() {return _resizable;}

  void setSize(unsigned int size) {_size = size;}
};

class Table {

  private:
  std::vector<Column> _columns;
  std::vector<std::vector<std::string>> _rows;

  public:
  void addColumn(Column c) {
    _columns.push_back(c);
  }

  void addRow(std::string t[]) {
    std::vector<std::string> _t;
    for(int i = 0; i < _columns.size(); i++) {
      _t.push_back(t[i]);

      if((_columns.at(i).getSize() < t[i].length()) && (_columns.at(i).isResizable())) {
        _columns.at(i).setSize(t[i].length());
      }
    }
    _rows.push_back(_t);
  }

  void draw() {
    // just making a list (string list) of headers
    std::vector<std::string> headers;
    for (int i = 0; i < _columns.size(); i++) 
      headers.push_back(_columns.at(i).getHeading());

    printSeparator('=', _columns);
    printRow(headers, _columns, true);
    printSeparator('=', _columns);

    for (int i=0; i<_rows.size(); i++) {
      printRow(_rows.at(i), _columns, false);
      printSeparator('-', _columns);
    }
  }


  private: 
  void printSeparator(char dash, std::vector<Column> columns) {
    std::cout << '+';
    for (int i=0; i<columns.size(); i++) {
      int k = columns.at(i).getSize();
      for(int j = 0; j<(k + columns.at(i).getPadding()*2); j++) std::cout << dash;
      std::cout << '+';
    }
    std::cout << std::endl;
  }

  void printRow(std::vector<std::string> v, std::vector<Column> c, bool isHeader) {
    // starting the row
    std::cout << '|';

    std::vector<std::string> buffer;

    for (int i = 0; i < c.size(); i++) {

      /* the value of this variable 'value' will be updated 
      (don't use it for reference to the original value) */
      std::string value = v.at(i);

      // extra space remaining the column after the value
      int diff;
      if(c.at(i).getSize() >= value.length()) {
        diff = c.at(i).getSize() - value.length();
      }
      else {
        diff = 0;
        value = value.substr(0, c.at(i).getSize());
      }

      for (int j = 0; j < diff; j++) {
        switch((isHeader ? c.at(i).getHeadingAlignment() : c.at(i).getColumnAlignment())) {
          case Column::RIGHT_ALIGN: {
            value.insert(0, " ");
            break;
          }
          case Column::CENTER_ALIGN: {
            if (j%2 == 0) value.append(" ");
            if (j%2 == 1) value.insert(0, " ");
            break;
          }
          default: value.append(" ");
        }
      }

      for (int j = 0; j < c.at(i).getPadding(); j++) {
        value.append(" ");
        value.insert(0, " ");
      }

      // printing the value
      std::cout << value << "|";

      // adjusting the buffer for incomplete values
      if(c.at(i).getSize() < v.at(i).length()) {
        buffer.push_back(
          v.at(i).substr(
            c.at(i).getSize(), 
            v.at(i).length()-c.at(i).getSize()
          )
        );
      }
      else buffer.push_back("");
    }
    // ending the row
    std::cout << std::endl;

    // checking if buffer is empty or not
    for (int i = 0; i < buffer.size(); i++) {
      if (buffer.at(i) != "") {
        printRow(buffer, c, isHeader);
        break;
      }
    }
  }

};