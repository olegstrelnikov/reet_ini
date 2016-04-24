/*
 * read_ini.hpp
 *
 *  Created on: Apr 7, 2016
 *      Author: ois
 */

#ifndef READ_INI_HPP_
#define READ_INI_HPP_

#include <string>
#include <map>
#include <iomanip>
#include <fstream>

namespace reet {
	namespace ini {
		inline std::map<std::string, std::string> readIni(char const* fn) {
			std::map<std::string, std::string> par;
			//Parameters from wmext.dat
			std::ifstream fpar(fn, std::ios_base::in | std::ios_base::binary);
			while (fpar) {
				std::string key;
				std::getline(fpar, key, '=');
				if (key.length() > 0 && key[0] == '\r') {
					key.erase(0, 1);
				}
				std::string val;
				std::getline(fpar, val, '\n');
				if (val.length() > 0 && val[val.length() - 1] == '\r') {
					val.erase(val.length() - 1, 1);
				}
				if (key != "" && key[0] != '#') {
					par.insert(std::make_pair(key, val));
				}
			}
			return par;
		} //getParFromFile()
	}
}

#endif /* READ_INI_HPP_ */
