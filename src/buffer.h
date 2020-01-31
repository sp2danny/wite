
#pragma once

#include <vector>
#include <string>

#include "common.h"

enum ColCode { ccBlack, ccYellow, ccRed, ccGreen, ccBlue };

struct AdornedChar
{
	char ch;
	bool bold;
	bool mark;
	ColCode col;
};

struct AdornedLine
{
	std::string plain_line;
	std::vector<AdornedChar> line;
	bool bookmark;
};

struct Buffer
{
	std::vector<AdornedLine> buffer;
	bool modified;
	std::string file_name;
	bool has_mark;
	bool block_mark;
	Pos mark_in, mark_out;
	void performAdorn();
};



