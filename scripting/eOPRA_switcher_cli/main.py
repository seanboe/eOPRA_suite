import click
import serial
import serial.tools.list_ports

from src.utilities import USBTalk

usb_device = click.make_pass_decorator(USBTalk, ensure=True)

@click.group(invoke_without_command=True)
@click.option('--port', '-p', default='', help='Manually select the device communications port')
@click.option('--baud_rate', '-b', default=112500, help='This is the serial baud rate')
@usb_device
def cli(usb_device, port, baud_rate):

  if port:
    usb_device.port = port
  else:
    for port in list(serial.tools.list_ports.comports()):
      if "Pico" in port.description:
        usb_device.port = port.device
        click.echo(f"Device found on port {usb_device.port}")

  if baud_rate:
    usb_device.baud_rate = baud_rate

  try:
    usb_device.serial_device = serial.Serial(port=usb_device.port, baudrate=usb_device.baud_rate, timeout=usb_device.serial_timeout)
  except:
    click.echo("Error communicating to device. Try selecting another port or verifying the USB connection.")
    exit()

  


@cli.command()
@usb_device
def write_read(usb_device):
  usb_device.write_read([0x05, 0x07])






def read_config():
  pass
  
def write_config():
  pass


def read_ports():
  pass

def write_ports():
  pass

def verify_net_comms():
  pass