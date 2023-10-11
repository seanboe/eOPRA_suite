import serial
import serial.tools.list_ports


if __name__ == "__main__":
  for port in list(serial.tools.list_ports.comports()):
    print(port.description)

    if "Pico" in port.description:
      port = port.device
      print(port)

      serial_device = serial.Serial(port=port, baudrate=112500, timeout=0.5)
      serial_device.write(bytes("hello", "ascii"))
      serial_device.close()




      # device.comm_params['port'] = port.device
      # click.echo(f"Device found on port {device.port}")