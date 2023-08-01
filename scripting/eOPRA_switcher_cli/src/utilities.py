import serial

class USBTalk:

  class Commands:
    START = 0x0


  def __init__(self, serial_port):
    self.serial_port = serial_port
  


