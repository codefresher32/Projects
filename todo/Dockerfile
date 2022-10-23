# Base Image
#  - using node becuase it is the required runtime 
FROM node:alpine

# Defining a workir so our apllication code is in a specific folder for organizing our container
WORKDIR /app

# Copying package.json as it includes project defination our our react project and is required to run the project
# Only copying this file specifily 
#   because this file is the least likely to change
COPY package*.json .

# Now installing node because it's requirements can change over time 
RUN npm install

# Copying other file in the container directory
COPY . .

# Exposing port in the container
# It is required in documentation
EXPOSE 3000

# Starting the app
CMD npm start

