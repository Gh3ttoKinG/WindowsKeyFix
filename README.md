# WindowsKeyFix

Unbinds the Office Key (Shift+Control+Alt+Win) related shortcuts, allowing you to use Office+W in other applications.

Full list of unbound shortcuts and their original behavior:
- `Office`: Opens Office UWP app
- `Office + D`: Opens OneDrive
- `Office + L`: Opens LinkedIn by opening `https://go.microsoft.com/fwlink/?linkid=2044786` (which redirects to `https://www.linkedin.com/?trk=Officekey`) in the default browser
- `Office + N`: Opens OneNote for Windows 10 UWP app
- `Office + O`: Opens Outlook
- `Office + P`: Opens PowerPoint
- `Office + T`: Opens Teams by opening `https://go.microsoft.com/fwlink/?linkid=2044782` (which reditects to `https://teams.microsoft.com/`) in the default browser
- `Office + W`: Opens Word
- `Office + X`: Opens Excel
- `Office + Y`: Opens Yammer by opening `https://go.microsoft.com/fwlink/?linkid=2044904` (which reditects to `https://www.yammer.com/`) in the default browser
- `Office + Space`: Opens the emoji picker

Extended by some Windows Key related shortcuts, disabling annoying shortcuts like the Feedback Hub.
- `Office + Space`: Language Bar (and select the next language immmediately)
- `Office + C`: Opens Cortana
- `Office + F`: Opens Feedback Hub
- `Office + Q`: Opens Search
- `Office + S`: Opens Search
- `Office + U`: Opens Ease of Access
- `Office + W`: Opens Whiteboard

You'll need to compile the script into a binary, and place it in `C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup` so it will run on startup.

# Virtual-Key Codes
To get the Virtual-Key Codes visit the following Microsoft website:

https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
