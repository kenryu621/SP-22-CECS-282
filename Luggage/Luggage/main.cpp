#include<iomanip>
#include<iostream>
#include<string>
#include<vector>

class luggage {
protected:
	std::string type;
	int serial_num;
	static int serial;
	static int luggage_count;
	static double luggage_volume;
public:
	luggage() {
		serial_num = ++serial;
		++luggage_count;
	}
	virtual double getVolume() = 0;
	virtual void removeItemCount() = 0;
	virtual void removeItemVolume(double v) = 0;
	std::string getType() {
		return type;
	}
	int getSerial() {
		return serial_num;
	}
	static int totalCount() {
		return luggage_count;
	}
	static double totalVolume() {
		return luggage_volume;
	}
	friend std::ostream& operator<<(std::ostream& output, luggage* right);
};

class box :public luggage {
private:
	double width, height, length;
	static int box_count;
	static double box_volume;
public:
	double getVolume() {
		return width * height * length;
	}
	box(double w, double h, double l) : luggage() {
		this->width = w;
		this->height = h;
		this->length = l;
		luggage::type = "Box";
		++box_count;
		box_volume += this->getVolume();
		luggage_volume += this->getVolume();
	}
	void removeItemCount() {
		--box_count;
		--luggage::luggage_count;
	}
	void removeItemVolume(double v) {
		box_volume -= v;
		luggage::luggage_volume -= v;
	}
	static int totalCount() {
		return box_count;
	}
	static double totalVolume() {
		return box_volume;
	}
};

class sphere :public luggage {
private:
	double radius;
	static int sphere_count;
	static double sphere_volume;
public:
	double getVolume() {
		return 4 * 3.14 * radius * radius * radius / 3;
	}
	sphere(double r) : luggage() {
		this->radius = r;
		luggage::type = "Sphere";
		++sphere_count;
		sphere_volume += this->getVolume();
		luggage_volume += this->getVolume();
	}
	void removeItemCount() {
		--sphere_count;
		--luggage::luggage_count;
	}
	void removeItemVolume(double v) {
		sphere_volume -= v;
		luggage::luggage_volume -= v;
	}
	static int totalCount() {
		return sphere_count;
	}
	static double totalVolume() {
		return sphere_volume;
	}
};

class cube :public luggage {
private:
	double width;
	static int cube_count;
	static double cube_volume;
public:
	double getVolume() {
		return width * width * width;
	}
	cube(double w) : luggage() {
		this->width = w;
		luggage::type = "Cube";
		++cube_count;
		cube_volume += this->getVolume();
		luggage_volume += this->getVolume();
	}
	void removeItemCount() {
		--cube_count;
		--luggage::luggage_count;
	}
	void removeItemVolume(double v) {
		cube_volume -= v;
		luggage::luggage_volume -= v;
	}
	static int totalCount() {
		return cube_count;
	}
	static double totalVolume() {
		return cube_volume;
	}
};

class pyramid :public luggage {
private:
	double base;
	double height;
	static int pyramid_count;
	static double pyramid_volume;
public:
	double getVolume() {
		return height * base * base / 3;
	}
	pyramid(double b, double h) : luggage() {
		this->base = b;
		this->height = h;
		luggage::type = "Pyramid";
		++pyramid_count;
		pyramid_volume += this->getVolume();
		luggage_volume += this->getVolume();
	}
	void removeItemCount() {
		--pyramid_count;
		--luggage::luggage_count;
	}
	void removeItemVolume(double v) {
		pyramid_volume -= v;
		luggage::luggage_volume -= v;
	}
	static int totalCount() {
		return pyramid_count;
	}
	static double totalVolume() {
		return pyramid_volume;
	}
};

class cylinder :public luggage {
private:
	double radius;
	double length;
	static int cylinder_count;
	static double cylinder_volume;
public:
	double getVolume() {
		return 3.14 * radius * radius * length;
	}
	cylinder(double r, double l) : luggage() {
		this->radius = r;
		this->length = l;
		luggage::type = "Cylinder";
		++cylinder_count;
		cylinder_volume += this->getVolume();
		luggage_volume += this->getVolume();
	}
	void removeItemCount() {
		--cylinder_count;
		--luggage::luggage_count;
	}
	void removeItemVolume(double v) {
		cylinder_volume -= v;
		luggage::luggage_volume -= v;
	}
	static int totalCount() {
		return cylinder_count;
	}
	static double totalVolume() {
		return cylinder_volume;
	}
};

int luggage::serial = 0;
int luggage::luggage_count = 0;
double luggage::luggage_volume = 0.0;
int box::box_count = 0;
double box::box_volume = 0.0;
int sphere::sphere_count = 0;
double sphere::sphere_volume = 0.0;
int cube::cube_count = 0;
double cube::cube_volume = 0.0;
int pyramid::pyramid_count = 0;
double pyramid::pyramid_volume = 0.0;
int cylinder::cylinder_count = 0;
double cylinder::cylinder_volume = 0.0;

std::ostream& operator<<(std::ostream& output, luggage* right) {
	output << std::left << std::setw(10) << right->type + ": ";
	if (right->type == "Box") {
		output << std::fixed << std::setw(10) << std::setprecision(1) << right->getVolume();
	}
	else if (right->type == "Sphere") {
		output << std::fixed << std::setw(10) << std::setprecision(1) << right->getVolume();
	}
	else if (right->type == "Cube") {
		output << std::fixed << std::setw(10) << std::setprecision(1) << right->getVolume();
	}
	else if (right->type == "Pyramid") {
		output << std::fixed << std::setw(10) << std::setprecision(1) << right->getVolume();
	}
	else if (right->type == "Cylinder") {
		output << std::fixed << std::setw(10) << std::setprecision(1) << right->getVolume();
	}
	output << " (SN:" << right->serial_num << ")";
	return output;
}

int main() {
	std::vector<luggage*> container;
	int user_input;
	double w, h, l, r, b;
	do {
		std::cout << "1) Add luggage to storage container\n";
		std::cout << "2) Remove luggage from storage container\n";
		std::cout << "3) Show all luggage\n";
		std::cout << "4) Show total volumes\n";
		std::cout << "5) Quit\n\n";
		std::cout << "Your input is: ";
		std::cin >> user_input;
		std::cout << std::endl;
		if (user_input == 1) {
			std::cout << "Select the one of the following luggage type:\n";
			std::cout << "1) Box\n";
			std::cout << "2) Sphere\n";
			std::cout << "3) Cube\n";
			std::cout << "4) Pyramid\n";
			std::cout << "5) Cylinder\n";
			std::cout << "Your input is: ";
			std::cin >> user_input;
			std::cout << std::endl;
			if (user_input == 1) {
				std::cout << "Enter the width: ";
				std::cin >> w;
				std::cout << "Enter the height: ";
				std::cin >> h;
				std::cout << "Enter the length: ";
				std::cin >> l;
				luggage* new_box = new box(w, h, l);
				container.push_back(new_box);
				std::cout << "Your box is added to the luggage.\n";
			}
			else if (user_input == 2) {
				std::cout << "Enter the radius: ";
				std::cin >> r;
				luggage* new_sphere = new sphere(r);
				container.push_back(new_sphere);
				std::cout << "Your sphere is added to the luggage.\n";
			}
			else if (user_input == 3) {
				std::cout << "Enter the width: ";
				std::cin >> w;
				luggage* new_cube = new cube(w);
				container.push_back(new_cube);
				std::cout << "Your cube is added to the luggage.\n";
			}
			else if (user_input == 4) {
				std::cout << "Enter the base: ";
				std::cin >> b;
				std::cout << "Enter the height: ";
				std::cin >> h;;
				luggage* new_pyramid = new pyramid(b, h);
				container.push_back(new_pyramid);
				std::cout << "Your pyramid is added to the luggage.\n";
			}
			else if (user_input == 5) {
				std::cout << "Enter the radius: ";
				std::cin >> r;
				std::cout << "Enter the length: ";
				std::cin >> l;
				luggage* new_cylinder = new cylinder(r, l);
				container.push_back(new_cylinder);
				std::cout << "Your cylinder is added to the luggage.\n";
			}
			else {
				std::cout << "Invalid input, please try again.\n";
			}
			user_input = 1;
		}
		else if (user_input == 2) {
			int count = 0, idx = 0;
			for (auto l : container) {
				std::cout << std::left << std::setw(5) << std::to_string(++count) + ") " << l << std::endl;
			}
			std::cout << "\nInput the serial number of the item that you want to remove.\n";
			std::cout << "Your input is: ";
			std::cin >> user_input;
			std::cout << std::endl;
			for (auto l : container) {
				if (l->getSerial() == user_input) {
					l->removeItemCount();
					l->removeItemVolume(l->getVolume());
					break;
				}
				++idx;
			}
			if (idx == count) {
				std::cout << "Invalid input, item does not exist.\n";
			}
			else {
				container.erase(container.begin() + idx);
				std::cout << "Your selected item is removed from the container.\n";
			}
			user_input = 2;
		}
		else if (user_input == 3) {
			int count = 0;
			for (auto l : container) {
				std::cout << std::left << std::setw(5) << std::to_string(++count) + ") " << l << std::endl;
			}
			std::cout << std::endl << std::setw(25) << std::left << "Total volume: " << luggage::totalVolume() << std::endl;
			std::cout << std::endl << std::setw(25) << std::left << "Total luggage items: " << luggage::totalCount() << std::endl;
			if (box::totalCount() > 0) {
				std::cout << std::setw(25) << std::left << "Total boxes: " << box::totalCount() << std::endl;
			}
			if (sphere::totalCount() > 0) {
				std::cout << std::setw(25) << std::left << "Total spheres: " << sphere::totalCount() << std::endl;
			}
			if (cube::totalCount() > 0) {
				std::cout << std::setw(25) << std::left << "Total cubes: " << cube::totalCount() << std::endl;
			}
			if (pyramid::totalCount() > 0) {
				std::cout << std::setw(25) << std::left << "Total pyramids: " << pyramid::totalCount() << std::endl;
			}
			if (cylinder::totalCount() > 0) {
				std::cout << std::setw(25) << std::left << "Total cylinders: " << cylinder::totalCount() << std::endl;
			}
		}
		else if (user_input == 4) {
			std::cout << std::left << std::setw(15) << "Item Type" << std::right << std::setw(15) << "Total Volume" << std::endl;
			if (box::totalVolume() > 0) {
				std::cout << std::setw(15) << std::left << "Box: " << std::right << std::setw(15) << box::totalVolume() << std::endl;
			}
			if (sphere::totalVolume() > 0) {
				std::cout << std::setw(15) << std::left << "Sphere: " << std::right << std::setw(15) << sphere::totalVolume() << std::endl;
			}
			if (cube::totalVolume() > 0) {
				std::cout << std::setw(15) << std::left << "Cube: " << std::right << std::setw(15) << cube::totalVolume() << std::endl;
			}
			if (pyramid::totalVolume() > 0) {
				std::cout << std::setw(15) << std::left << "Pyramid: " << std::right << std::setw(15) << pyramid::totalVolume() << std::endl;
			}
			if (cylinder::totalVolume() > 0) {
				std::cout << std::setw(15) << std::left << "Cylinder: " << std::right << std::setw(15) << cylinder::totalVolume() << std::endl;
			}
			std::cout << std::setw(15) << std::left << "Luggage: " << std::right << std::setw(15) << luggage::totalVolume() << std::endl;
		}
		else if (user_input == 5) { break; }
		else { std::cout << "Invalid input, please try again!\n"; }
		std::cout << std::endl;
	} while (user_input != 5);
	for (auto l : container) {
		delete l;
	}
	container.clear();
	return 0;
}