# Minimum Operations

In a text file, there is a single character H. Your text editor can execute only two operations in this file: Copy All and Paste. Given a number n, write a method that calculates the fewest number of operations needed to result in exactly n H characters in the file. Be smart about how you utilize the memory!

- Prototype: `def minOperations(n)`
- Returns an integer
- If `n` is impossible to achieve, return `0`


- **Exemple:**
```python
Number to reach : 9

| Step | Action     | Result            |
|------|------------|-------------------|
| 0    | Start      | H                 |
| 1    | Copy All   | H (copied)        |
| 2    | Paste      | HH  (2)           |
| 3    | Paste      | HHH (3)           |
| 4    | Copy All   | HHH (copied)      |
| 5    | Paste      | HHHHHH (6)        |
| 6    | Paste      | HHHHHHHHH (9)     |
```

## Étapes du programme pour n = 9

| Étape | Valeur de `number` | Diviseur trouvé (`div`) | Opérations cumulées | Explication                                                                 |
|-------|---------------------|--------------------------|----------------------|------------------------------------------------------------------------------|
| 1     | 9                   | 3                        | 3                    | 3 est le plus petit diviseur de 9                                           |
| 2     | 3                   | 3                        | 6                    | 3 est le plus petit diviseur de 3                                           |
| 3     | 1                   | -                        | 6                    | Le nombre est réduit à 1, fin du traitement                                 |

✅ **Résultat final : 6 opérations**
🔍 **Décomposition en facteurs premiers** : 9 = 3 × 3 → donc 3 + 3 = 6 opérations
