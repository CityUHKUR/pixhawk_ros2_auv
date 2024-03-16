FROM ros:humble

RUN apt-get update && apt-get install -y \
    git python3.10 python3-pip

RUN pip install pymavlink pyserial setuptools==58.2.0

RUN apt-get update && apt-get install -y nano vim

COPY ./entry_point.sh /entry_point.sh

ENTRYPOINT ["/entry_point.sh"]

