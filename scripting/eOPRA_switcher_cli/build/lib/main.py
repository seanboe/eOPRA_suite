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
@click.option('--time', '-t', default='', help='Set the internal time')
@click.option('--stim_on', '-p', default=1, help='Set stimulation on')
@click.option('--stim_port', '-sp', default=8, help='Set the stimulation port')
@click.option('--tft_on', '-tft', default=1, help='Set the tft on/off')
@click.option('--broadcast_on', '-b', default=1, help='Set MQTT broadcasting on/off')
@click.option('--debug_on', '-b', default=1, help='Set debugging on/off')
@click.option('')
@usb_device
def set(usb_device):
  """
  configure variables on the device
  """
  click.echo(usb_device.write_read([0x05, 0x07]))


@cli.command()
@click.option('--time', '-t', default='', help='Get the internal time')
@click.option('--stim_on', '-p', default='', help='Get stimulation enable status')
@click.option('--stim_port', '-sp', default='', help='Get the enabled stimulation port')
@click.option('--tft_on', '-tft', default='', help='Get the tft status')
@click.option('--broadcast_on', '-b', default='', help='Get MQTT broadcasting status')
@click.option('--debug_on', '-b', default='', help='Get debug enable status')
@click.option('--devices', 'd', default='', help='Get the connected devices')
@usb_device
def get(usb_device):
  pass


@cli.command()
@usb_device
def broadcast(usb_device):
  """
  Broadcast commands from one device to another over MQTT
  """
  pass




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


@cli.result_callback()
@usb_device
def terminator(device, result, **kwargs):
  try:
    usb_device.serial_device.close()
  except:
    click.echo('Unable to close serial port.')  