#pragma once
#include "Shape.hpp"

class GDIWRAPPER_API EllipseShape : public Shape
{
public:
	EllipseShape();
	EllipseShape(int width, int height);
	EllipseShape(std::pair<int, int> size);
	EllipseShape(int x, int y, int width, int height);
	EllipseShape(std::pair<int, int> pos, std::pair<int, int> size);
	EllipseShape(RECT rect);

	void setFillColor(unsigned char r, unsigned char g, unsigned char b) override;
	void setOutlineColor(unsigned char r, unsigned char g, unsigned char b) override;
	void setOutlineThickness(int outlineThickness) override;

	void setPosition(int x, int y) override;
	void setPosition(std::pair<int, int> pos) override;
	void setSize(int width, int height) override;
	void setSize(std::pair<int, int> size) override;
	void setRect(RECT rect) override;

	void move(int x, int y) override;
	void move(std::pair<int, int> distance) override;

	std::pair<int, int> getPosition() const override;
	std::pair<int, int> getSize() const override;
	RECT getRect() const override;

	RECT draw(HDC hDC) const override;

private:
	void drawOutline(HDC hDC, RECT outlineRect) const;
	RECT getOutlineRect() const;

private:
	int m_x, m_y;
	int m_width, m_height;
	int m_outlineThickness;
	COLORREF m_fillColor, m_outlineColor;
};