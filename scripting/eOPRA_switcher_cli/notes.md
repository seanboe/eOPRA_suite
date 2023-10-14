# Deploy Notes

- python3 setup.py sdist bdist_wheel
- pip install dist/eopra_switcher-0.0.1.tar.gz
- pip uninstall eOPRA_switcher (possibly multiple times)
<!-- - python3 -m pip install --upgrade twine -->
- use __token__ as the password

pypi-AgEIcHlwaS5vcmcCJDQyN2YzYTk2LWNjNGMtNGIxZi05OGVkLTAzYWQzODQwN2RkNQACKlszLCI5NDhlZTVjOC1lOTA5LTQxYzEtYTlkMy1lMWExNTUxOTY0NTciXQAABiBNZw-E1M0PNxhHDE1uWxuFzI6QOBlcugZjnK2m4uUZYw

- python3 -m twine upload --repository pypi dist/*



set port number
set broadcast
set stimulation off
set stream
- Plot

set debug

get internal time
get connected devices


beep


@cli.command()
@click.option('--time', '-t', default='', help='Set the internal time')
@click.option('--stim_on', '-p', default=1, help='Set stimulation on')
@click.option('--stim_port', '-sp', default=8, help='Set the stimulation port')
@click.option('--tft_on', '-tft', default=1, help='Set the tft on/off')
@click.option('--broadcast_on', '-b', default=1, help='Set MQTT broadcasting on/off')
@click.option('--debug_on', '-b', default=1, help='Set debugging on/off')
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
