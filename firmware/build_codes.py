with open('CommCodes.yaml', 'r') as yaml_settings:
  with open('./lib/CommCodes.h', 'w') as CommCodes_h:

    CommCodes_h.write("// ****** GENERATED ON COMPILE ******\n")
    CommCodes_h.write("\n")
    CommCodes_h.write("#ifndef COMM_CODES_H\n")
    CommCodes_h.write("#define COMM_CODES_H\n")
    CommCodes_h.write("\n")

    yaml_lines = yaml_settings.readlines()
    try:
      for yaml_line in yaml_lines:
        if yaml_line[0] == "#":
          CommCodes_h.write(f"//{yaml_line[1:]}")
        elif len(yaml_line) > 1:
          key, value = yaml_line.split(":")
          CommCodes_h.write(f"#define {key.upper()} {value.strip()}\n")
        else:
          CommCodes_h.write("\n")
    except:
      print("COMM CODE UPDATE: FAIL")
      raise Exception("Failed Communication Code Generation")
    
    CommCodes_h.write("#endif")

print("COMM CODE UPDATE: PASS")
