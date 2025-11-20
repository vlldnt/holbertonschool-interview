#!/usr/bin/node

const request = require('request');

const movieNumber = process.argv[2];

if (!movieNumber) {
  console.log('Need to write: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

// Api Starwasr fetch to get movie information body
const url = `https://swapi-api.hbtn.io/api/films/${movieNumber}/`;

request(url, (err, res, body) => {
  if (err) {
    console.log('Movie not found. Try between 1 and 7.');
    process.exit(1);
  }

  const movie = JSON.parse(body);
  const urlsCharacters = movie.characters;

  // Loop to keep the order
  const printCharacter = (index) => {
    if (index >= urlsCharacters.length) {
      return;
    }

    // Request and print the character name
    request(urlsCharacters[index], (err, res, body) => {
      if (!err) {
        const character = JSON.parse(body);
        console.log(character.name);
      }
      printCharacter(index + 1);
    });
  };

  printCharacter(0);
});
