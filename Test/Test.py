import platform
import os

def is_wsl():
    # Check if running in WSL
    if "microsoft" in platform.uname().release.lower():
        return True
    # Check the /proc/version file for WSL-specific mentions
    try:
        with open("/proc/version", "r") as f:
            version_info = f.read().lower()
            if "microsoft" in version_info:
                return True
    except FileNotFoundError:
        return False
    return False

def is_bash():
    # Check if the shell is bash
    return os.getenv('SHELL', '').endswith('bash')

if __name__ == "__main__":
    if is_wsl() and is_bash():
        print("You are using bash in a WSL environment.")
    elif is_wsl():
        print("You are in a WSL environment, but not using bash.")
    else:
        print("This is not a WSL environment.")