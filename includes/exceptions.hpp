#pragma once

#include "pch.h"

class ExceptionSDLInitialize : public std::exception {
	public:
	const char * what() const throw() {
		return "SDL couldn't initialize";
	}
};

class ExceptionSDLWindow : public std::exception {
	public:
	const char * what() const throw() {
		return "SDL Window couldn't be opened";
	}
};


class ExceptionSDLRenderer : public std::exception {
	public:
	const char * what() const throw() {
		return "SDL Renderer couldn't be opened";
	}
};


class ArgumentError : public std::exception {
	private:
	std::string full_message;

	public:
	ArgumentError(const std::string& arg) : full_message("Unknown option: " + arg) {}
	const char * what() const throw() {
		std::cerr << "Use --help for more information" << std::endl;
		return full_message.c_str();
	}
};


// --------------- Menu --------------- //

class FileError : public std::exception {
	private:
	std::string full_message;

	public:
	FileError(const std::string& file) : full_message("Couldn't open file: " + file) {}
	const char * what() const throw() {
		return full_message.c_str();
	}
};


class MenuFileFormat : public std::exception {
	private:
	std::string full_message;

	public:
	MenuFileFormat(const std::string& file) : full_message( "Menu format error at line " + file) {}
	const char * what() const throw() {
		return full_message.c_str();
	}
};




