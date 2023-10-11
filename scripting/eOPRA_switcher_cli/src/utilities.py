import serial
import yaml
import click
import numpy as np
import time


class USBTalk:

  def __init__(self):

    with open('src/CommCodes.yaml', 'r') as file:
      self.comm_commands = yaml.safe_load(file)
      # for key in self.comm_commands.keys():
      #   self.comm_commands[key] = str(self.comm_commands[key])
    
    self.port = "/dev/cu.usbmodem1101"
    self.baud_rate = 112500
    self.serial_timeout = 0.5
    self.serial_device = None

    # Default
    # self.serial_device = serial.Serial(self.port, self.baud_rate, self.serial_timeout)
  


  def write_read(self, data:list):
    """
    Sends a list of readable commands to the device. The readable strings are converted to hex internally.
    data: Readable command strings in the form of a list
    """

    message = [self.comm_commands["start"]]
    message.append(np.random.randint(0, 255))
    message.extend(data)
    message.append(self.comm_commands["stop"])

    # for element in message:
    #   self.serial_device.write(str(bytes(element)))
    # print(type(message))

    # self.serial_device.write(bytearray([1, 2, 3]))
    print(bytearray(message))
    print(message[1])
    self.serial_device.write(bytearray(message))
    # self.serial_device.flush()

    # self.serial_device.write(str(bytearray([1, 2, 3, 4])))

    # print(message)
    # return

    # receive the response
    try:
      time.sleep(1)
      print(self.serial_device.in_waiting)
      output = self.serial_device.readline()
      print(output)
      print(list(output))
    except:
      click.echo('Unable to communicate (send or receive) data to device.')
      return None
    
    click.echo(output)
    
    return True

    # response = [float(x) for x in output.split(',') if x != '']

    # response.remove(actions.list['comm_termination'])

    # return response

