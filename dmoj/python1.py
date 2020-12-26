class Magic(object):
    def method(self):
        print 'Success' if self is None else 'Fail'

class Magic(object):
    def method(self):
        print 'Success'

m = Magic()
m.method()

