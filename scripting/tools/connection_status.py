import time
import serial
import serial.tools.list_ports

def main():
  try:
    connection_status = False
    while True:
      in_list = False
      for port in list(serial.tools.list_ports.comports()):
          if "Pico" in port.description:
            in_list = True

      if connection_status != in_list:
        if connection_status:
          print(f"Disconnected!")
        else:
          print("Connected!")
        connection_status = in_list

  except KeyboardInterrupt:
    print("Cya!")
    
if __name__ == "__main__":
  main()