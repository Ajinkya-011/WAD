1. Initialize a new npm project:
   ```
   npm init
   ```

2. Install Express.js and save it as a dependency:
   ```
   npm install express --save
   ```

3. Create an `index.js` file with the following content:
   ```javascript
   const express = require('express');
   const app = express();

   // Serve static files from the 'public' directory
   app.use(express.static('public'));

   // Start the server on port 4000
   app.listen(4000, () => {
       console.log("Server Has Started on PORT: 4000");
   });
   ```

4. Create a `public/index.html` file and add HTML content to display in the browser.

5. Run the server by executing:
   ```
   node index.js
   ```

6. Open a browser and navigate to `localhost:4000` to see your HTML content served by Express.
