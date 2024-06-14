#include <QApplication>
#include <iostream>

#include "main_window.h"
#include "registry_op.h"

int main(int argc, char* argv[]) {
  BOOL ret = metax::RegistryOp::Read();
  std::cout << ret << std::endl;

  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
