BOTLOADER_SIZE = 0x8000
BOTLOADER_FILE = "bootloader.bin"

with open(BOTLOADER_FILE, "rb") as f:
    raw_file = f.read()

bytes_to_pad = BOTLOADER_SIZE - len(raw_file)
padding = bytes([0xFF for _ in range(bytes_to_pad)])

with open(BOTLOADER_FILE, "wb") as f:
    f.write(raw_file + padding)
