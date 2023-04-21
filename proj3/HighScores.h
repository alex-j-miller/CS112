/*
 * HighScores.h
 *
 *  Created on: Feb 6, 2022
 *      Author: alex
 */

#ifndef HIGHSCORES_H_
#define HIGHSCORES_H_

class HighScores {
public:
	HighScores();

	//getters
	int getNumScores();
	int getScore(int index);

	//setters
	void addScore(int aScore);

private:
	int myScores[10];
	int myNumScores;

	int findLocationToInsert(int newScore);
	void shiftUp(int fromIndex);

};

#endif /* HIGHSCORES_H_ */
