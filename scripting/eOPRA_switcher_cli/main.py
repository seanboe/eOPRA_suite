import click
import serial
import serial.tools.list_ports
import time

class eOPRA_Switcher(object):
  def __init__(self):
    self.comm_params = {}
device = click.make_pass_decorator(eOPRA_Switcher, ensure=True)

@click.group(invoke_without_command=True)
@click.option('--port', '-p', default='', help='Manually select the device communications port')
@click.option('--baud_rate', '-b', default=112500, help='This is the serial baud rate')
@device
def cli(device, port, baud_rate):

  if port:
    device.comm_params['port'] = port
  else:
    for port in list(serial.tools.list_ports.comports()):
      if "__board__ name" in port.description:
        device.comm_params['port'] = port.device
        click.echo(f"Device found on port {device.port}")

  if baud_rate:
    device.comm_params['baud_rate'] = baud_rate

  try:
    device.comm_params['serial_device'] = serial.Serial(port=device.comm_parameters['port'], baudrate=device.comm_parameters['baudrate'], timeout=0.5)
  except:
    click.echo("Error communicating to device. Try selecting another port or verifying the USB connection.")
  


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