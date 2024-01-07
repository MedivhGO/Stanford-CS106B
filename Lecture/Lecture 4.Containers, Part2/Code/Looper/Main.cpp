#include "SoundPlayer.h"
#include "console.h"
#include "queue.h"
#include "filelib.h"
#include "strlib.h"
#include "simpio.h"
#include "vector.h"
#include <fstream>
#include <string>
using namespace std;

/* Directory where the loops live. */
const string kBaseDirectory = "loops/";

/* Type representing a sound clip. */
struct SoundClip {
    string filename; // Name of the file
    double length;   // How long to play it for
};

/* Returns a list of all the .loop files available to play. */
Vector<string> musicFileOptions() {
    Vector<string> result;
    for (string file: listDirectory(kBaseDirectory)) {
        if (endsWith(file, ".loop")) {
            result += file;
        }
    }
    sort(result.begin(), result.end());
    return result;
}

/* Prints out a menu of songs we can loop. */
void displayOptions(const Vector<string>& options) {
    for (int i = 0; i < options.size(); i++) {
        cout << i << ": " << options[i] << endl;
    }
}

/* Prompts the user to pick a music file, reprompting until they
 * make a selection.
 */
string chooseMusicFile() {
    Vector<string> options = musicFileOptions();
    displayOptions(musicFileOptions());

    while (true) {
        int choice = getInteger("Your choice: ");
        if (choice >= 0 && choice < options.size()) {
            return kBaseDirectory + options[choice];
        }
    }
}

/* Given the name of a loop file, loads the clips from
 * that file into a Queue.
 */
Queue<SoundClip> loadLoop(const string& filename) {
    /* See Chapter 3 of the textbook for details. */
    ifstream input(filename);

    Queue<SoundClip> result;

    /* The idiomatic "read all the lines of this file"
     * loop in C++.
     */
    for (string line; getline(input, line); ) {
        /* Each line has the form
         *
         * Filename Duration
         *
         * We'll split on a space, taking the first item
         * as the name of the file and the second as the
         * duration.
         */
        Vector<string> pieces = stringSplit(line, " ");

        /* Parse things into a SoundClip. */
        SoundClip clip;
        clip.filename = pieces[0];
        clip.length   = stringToReal(pieces[1]);

        result.enqueue(clip);
    }

    return result;
}

int main() {
    Queue<SoundClip> loop = loadLoop(chooseMusicFile());

    while (true) {
        SoundClip toPlay = loop.dequeue();
        playSound(toPlay.filename, toPlay.length);

        loop.enqueue(toPlay);
    }
}










