FROM node:18-bullseye

RUN apt-get update \
 && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    				   time curl build-essential gdb cmake git nano python3 emacs-nox vim dos2unix \
 && apt-get clean \
 && /bin/rm -rf /var/lib/apt/lists/*

RUN apt-get update \
 && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    				   gprolog \
 && apt-get clean \
 && /bin/rm -rf /var/lib/apt/lists/*

WORKDIR /app
EXPOSE 8000

RUN echo  export PATH='"'/app/bin:/app/bin/$(uname -s)-$(uname -m):/app/node_modules/.bin:/app:'${PATH}''"' >> /root/.bashrc
ENTRYPOINT ["/bin/bash","-i","-c","\"$@\"","--"]

