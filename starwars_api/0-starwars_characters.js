#!/usr/bin/node

const request = require("request");

const movieNumber = process.argv[2];

if (!movieNumber) {
  console.log("Need to write: ./0-starwars_characters.js <Movie ID>");
  process.exit(1);
}
// Fetch Starwars API with a get for the Movie ID
const url = `https://swapi-api.hbtn.io/api/films/${movieNumber}/`;

request(url, (error, response, body) => {
  if (error) {
    console.error(error);
    process.exit(1);
  }
  if (response.statusCode !== 200) {
    console.log("Movie not found. Try between 1 and 7.");
    process.exit(1);
  }

  const movie = JSON.parse(body);

  // List of URL fetched in the request before
  urlsCharacters = movie.characters;

  // For each url in the list of characters print the name of the character
  urlsCharacters.forEach((characterUrl) => {
    request(characterUrl, (err, res, charBody) => {
      if (!err) {
        const character = JSON.parse(charBody);
        console.log(character.name);
      }
    });
  });
});
