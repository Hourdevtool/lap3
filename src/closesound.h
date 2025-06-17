#include <BluetoothSerial.h>
#pragma once
bool shouldStop(BluetoothSerial &bt) {
  if (bt.available()) {
    char cmd = bt.read();
    if (cmd == '0') {
        bt.println("ปิดเสียง");
  
      return true;
    }
  }
  return false;
}
