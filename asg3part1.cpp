#include <iostream>
using namespace std;
int main() {
int a, b, c, d;
cout << "Enter IP address: ";
cin >> a >> b >> c >> d;
// Validate IP
if (a < 0 || a > 255 ||
b < 0 || b > 255 ||
c < 0 || c > 255 ||
d < 0 || d > 255) {
cout << "Invalid IP Address";
return 0;
}
cout << "\nEntered IP Address: "
<< a << "." << b << "." << c << "." << d << endl;
// Special address
if (a == 0) {
cout << "Special / Reserved Address" << endl;
cout << "Range: 0.0.0.0 - 0.255.255.255" << endl;
}
// Class A
else if (a >= 1 && a <= 126) {
cout << "\nClass: A" << endl;
cout << "Range: 1.0.0.0 - 126.255.255.255" << endl;
cout << "Default Mask: 255.0.0.0" << endl;
cout << "CIDR: /8" << endl;
cout << "Number of Networks: 126" << endl;
cout << "Usable Hosts per Network: 16777214" << endl;
cout << "Purpose: Large networks" << endl;
}
// Loopback
else if (a == 127) {
cout << "\nSpecial / Reserved Address" << endl;
cout << "Range: 127.0.0.0 - 127.255.255.255" << endl;
cout << "Purpose: Loopback testing" << endl;
}
// Class B
else if (a >= 128 && a <= 191) {
cout << "\nClass: B" << endl;
cout << "Range: 128.0.0.0 - 191.255.255.255" << endl;
cout << "Default Mask: 255.255.0.0" << endl;
cout << "CIDR: /16" << endl;
cout << "Number of Networks: 16384" << endl;
cout << "Usable Hosts per Network: 65534" << endl;
cout << "Purpose: Medium-sized networks" << endl;
}
// Class C
else if (a >= 192 && a <= 223) {
cout << "\nClass: C" << endl;
cout << "Range: 192.0.0.0 - 223.255.255.255" << endl;
cout << "Default Mask: 255.255.255.0" << endl;
cout << "CIDR: /24" << endl;
cout << "Number of Networks: 2097152" << endl;
cout << "Usable Hosts per Network: 254" << endl;
cout << "Purpose: Small networks" << endl;
}
// Class D
else if (a >= 224 && a <= 239) {
cout << "\nClass: D" << endl;
cout << "Range: 224.0.0.0 - 239.255.255.255" << endl;
cout << "Purpose: Multicast communication" << endl;
}
// Class E
else {
cout << "\nClass: E" << endl;
cout << "Range: 240.0.0.0 - 255.255.255.255" << endl;
cout << "Purpose: Experimental / Research" << endl;
}
return 0;
}
